#!/usr/bin/env python
import sys

import os
import pwd
import datetime
import time

import subprocess
import json

import urllib2
import urllib
import re

HEADER = {"Content-Type": "application/json"}
API_URL = "https://api.jarvice.com/jarvice"

def set_job_name_or_number(params, job_name, job_number):
	if job_number is not None:
		params['number'] = job_number
		if job_name is not None:
			raise RuntimeError("ERROR: Cannot set both job_number and job_name")
	if job_name is not None:
		params['name'] = job_name
		if job_number is not None:
			raise RuntimeError("ERROR: Cannot set both job_number and job_name")

	return params

def get(endpoint, params):
	url = API_URL + "/" + endpoint

	request = urllib2.Request(url, urllib.urlencode(params))
	response = urllib2.urlopen(request)

	return response

def get_lines(endpoint, params):
	ret = get(endpoint, params)
	return ret.read()

def get_json(endpoint, params):
	try:
		ret = get_lines(endpoint, params)
	except urllib2.HTTPError as e:
		if e.code == 404:
			ret = e.read()
			pass
		else:
			raise

	if ret == "":
		ret = "{}"
	
	return json.loads(ret)

def post_json(endpoint, params):
	url = API_URL + "/" + endpoint

	request = urllib2.Request(url, data=json.dumps(params), headers=HEADER)
	response = urllib2.urlopen(request)

	return json.load(response)

def action(username, apikey, action, job_name=None, job_number=None):
	params = {
		'username': username,
		'apikey': apikey,
		'action': action
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("action", params)

	if ret["status"] != "action requested":
		raise RuntimeError("ERROR: Failed to run action")

def shutdown(username, apikey, job_name=None, job_number=None):
	params = {
		'username': username,
		'apikey': apikey,
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("shutdown", params)

	if ret["status"] != "shutdown requested":
		raise RuntimeError("ERROR: Failed to shutdown job")

def submit(username, apikey, job_desc):
	params = job_desc

	user_params = {
		'username': username,
		'apikey': apikey
	}

	params["user"] = user_params

	ret = post_json("submit", params)

	#TODO: Validate that the post was successful by testing for the name/number of job

	return ret 

def terminate(username, apikey, job_name=None, job_number=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("terminate", params)

	if ret["status"] != "terminated":
		raise RuntimeError("ERROR: Failed to terminate job")

def connect(username, apikey, job_number=None, job_name=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("connect", params)

	return ret

def info(username, apikey, job_number=None, job_name=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("info", params)
	
	if not "url" in ret or not "about" in ret:
		raise RuntimeError("ERROR: Failed to get web service information")

	return ret

def jobs(username, apikey):
	params = {
		'username': username,
		'apikey': apikey
	}

	ret = get_json("jobs", params)
	
	return ret

def output(username, apikey, job_number=None, job_name=None, lines=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	if lines is not None:
		params["lines"] = lines

	ret = get_lines("output", params)

	return ret

def status(username, apikey, job_number=None, job_name=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	ret = get_json("status", params)

	# TODO: validate response

	return ret

def tail(username, apikey, job_number=None, job_name=None, lines=None):
	params = {
		'username': username,
		'apikey': apikey
	}

	params = set_job_name_or_number(params, job_name, job_number)

	if lines is not None:
		params["lines"] = lines

	ret = get_lines("tail", params)

	return ret

def lftp(cmds):
	FNULL = open(os.devnull, 'w')
	lftp_proc = subprocess.Popen(["lftp"], stderr=FNULL, stdin=subprocess.PIPE)
	lftp_proc.communicate(input=cmds)[0]

def upload_testcase(username, apikey, testid):
	# chmod after copy is done to allow profile reports to be overwritten
	cmds = """
open sftp://drop.jarvice.com
user %s %s
rm -rf /data/automated_test/%s
mkdir -p /data/automated_test/%s
cd /data/automated_test/%s
mirror -R .
bye
""" % (username, apikey, testid, testid, testid)
	return lftp(cmds)

def download_testcase(username, apikey, testid, job_name):
	cmds = """
open sftp://drop.jarvice.com
user %s %s
cd /data/automated_test/%s
mirror .
get /data/NACC-OUTPUT/%s.txt
rm -r /data/automated_test/%s
bye
""" % (username, apikey, testid, job_name, testid)

	return lftp(cmds)

def submit_testcase(username, apikey, testid, exe, args):
	_exe = "automated_test/%s/%s" % (testid, exe)
	_args = ' '.join(args)

	job_desc = {
		"app": "xilinx_runtime",
		"checkedout": False,
		"machine": {
			"nodes": "1",
			"type": "nx1"
		},
		"application": {
			"geometry": "800x600",
			"staging": False,
			"command": "run",
			"parameters": {
				"executable": _exe,
				"args": _args
			}
		},
		"vault": {
			"readonly": False,
			"password": "",
			"force": False,
			"name": "drop.jarvice.com",
			"objects": []
		}
	}

	job = submit(username, apikey, job_desc)

	return job

cdir = os.getcwd()
rundate = datetime.datetime.now();

user = pwd.getpwuid(os.getuid())[0]
testid = user + "-" + rundate.strftime("%d%m%y_%S")

if len(sys.argv) != 1:
	exe = sys.argv[1]
else:
	exe = os.environ['EXE']

if len(sys.argv) != 1:
	args = sys.argv[2:len(sys.argv)]
else:
	args = os.environ['ARGS']

try:
	nimbix_user = os.environ['NIMBIX_USER']
	nimbix_apikey = os.environ['NIMBIX_APIKEY']
except KeyError:
	nimbix_user = ""
	nimbix_apikey = ""

if nimbix_user == "" or nimbix_apikey == "":
	creds_filename = os.path.expanduser("~/.nimbix_creds.json")
	if os.path.isfile(creds_filename):
		creds_fp = open(creds_filename)
		creds = json.load(creds_fp)
		nimbix_user = creds['username']
		nimbix_apikey = creds['api-key']
	else:
		print "ERROR: Must set NIMBIX_USER or have ~/.nimbix_creds.json file"
		sys.exit(-1)

if exe == "":
	print "ERROR: Must define the application executable"
	sys.exit(-1)

print "Uploading Test Case"

upload_testcase(nimbix_user, nimbix_apikey, testid)

print "Upload Complete"
print
print "Testcase: " + exe + " " + ' '.join(args)

# Sleep for 10 seconds before trying to execute as sometimes the uploads are not
# instantaneous
time.sleep(10)


job = submit_testcase(nimbix_user, nimbix_apikey,
                      testid, exe, args)

print "Job: " + str(job['name']) + " #" + str(job['number'])


# Wait at maximum 1 hour for test to move to running state
queue_timeout = datetime.datetime.now() + datetime.timedelta(minutes=60)

rc = 127
timeout = None
api_fails = 0

while True:
	# Sleep for 1 seconds before checking again
	time.sleep(1)

	try:
		current_status = status(nimbix_user, nimbix_apikey, job_number=job['number'])
	except urllib2.URLError:
		# If we fail to access the url a couple times then pass on the failure.
		if api_fails > 5:
			raise
		else:
			api_fails += 1

		continue

	state = current_status[str(job['number'])]['job_status'];

	#  First time state = RUNNING set timeout
	if state == 'RUNNING':
		if not timeout:
			timeout = datetime.datetime.now() + datetime.timedelta(minutes=timeout)

		# Test Timeout
		if datetime.datetime.now() > timeout:
			terminate(nimbix_user, nimbix_apikey,
			          job_number=job['number'])
			rc = 140
			break

	# Infrastructure Failure or invalid arguments
	if state == 'ENDED':
		raise RuntimeError("ERROR: Test entered ENDED state")

	current_time = datetime.datetime.now()

	# Infrastructure Failure if queue timeout exceeded
	if current_time > queue_timeout:
		terminate(nimbix_user, nimbix_apikey,
		                  job_number=job['number'])
		raise RuntimeError("ERROR: Queue timeout exceeded")

	# Need to determine a way to get better error status from Nimbix
	if state == 'COMPLETED':
		rc = 0
		break

	# Need to determine a way to get better error status from Nimbix
	if state == 'COMPLETED WITH ERROR':
		rc = 1
		break

if rc == 0:
	rc_str = "Successfully"
else:
	rc_str = "with Errors"

print "Job Completed %s" % rc_str

print "Downloading Test Case"

download_testcase(nimbix_user, nimbix_apikey, testid, job['name'])

output = output(nimbix_user, nimbix_apikey,
                        job_number=job['number'])
print "Download Complete"
print
print output

sys.exit(rc)

