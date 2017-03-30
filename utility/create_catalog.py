#!/usr/bin/env python

#
# This searches and indexes all of the example designs with description.json
# index files. To omit an example from the index, add "sdx_gui": "false" to
# the description.json.
#
# This should be run at the example root directory. The argument is the
# name of the output index file.
#

import os
import json
import collections
import sys
import subprocess

if len(sys.argv) is not 2:
    print "Usage: %s <catalog>.json" % sys.argv[0]
    sys.exit(os.EX_USAGE)

index_filename = sys.argv[1]

def addexample(path):
    example = collections.OrderedDict()
    example["name"] = os.path.basename(path)
    example_json_file = os.path.join(path, "description.json")
    if (os.path.isfile(example_json_file)):
        with open(example_json_file) as json_file:
            data = json.load(json_file)
            if data.get("sdx_gui"):
                supported_in_gui = data.get("sdx_gui")
                if supported_in_gui.lower() not in [ "true", "1", "yes" ]:
                    return None
            if data.get("overview"):
                example["description"] = data.get("overview")
            if data.get("example"):
                example["displayName"] = data.get("example")
            if data.get("revision"):
                revisions = data.get("revision")
                highestVersion = ""
                for r in range(len(revisions)):
                    revision = revisions[r]
                    if revision["version"]:
                       highestVersion = revision["version"]
                # TODO: choose latest revision
                example["version"] = highestVersion
            if data.get("contributors"):
                contributors = data.get("contributors")
                for r in range(len(contributors)):
                    contributor = contributors[r]
                    author = contributor["group"]
                    example["author"] = author
    print "adding %s" % path
    return example

def get_git_branch():
    branch = subprocess.check_output(["git", "rev-parse", "--abbrev-ref", "HEAD"])
    branch = branch.strip()
    return branch

def searchdir(dir):
    if (not os.path.isdir(dir)):
        print "%s not found, but indexed in parent summary.json" % dir
        emptycat = collections.OrderedDict()
        emptycat["categories"] = []
        emptycat["examples"] = []
        return emptycat
    dirnames = [entry for entry in os.listdir(dir) if os.path.isdir(os.path.join(dir,entry))]
    index = collections.OrderedDict()
    subdirs = {}
    category = collections.OrderedDict()
    category["name"] = os.path.basename(dir)
    category["displayName"] = ""
    category["description"] = ""
    category["categories"] = []
    category["examples"] = []
    summary_json_file = os.path.join(dir, "summary.json")
    if (os.path.isfile(summary_json_file)):
        with open(summary_json_file) as json_file:
            data = json.load(json_file)
            if data.get("overview"):
                category["displayName"] = data.get("overview")
            if data.get("description"):
                category["description"] = data.get("description")
            if data.get("subdirs"):
                subdirs = data["subdirs"]
    if (not subdirs):
        subdirs = dirnames
    subdirs = sorted(subdirs)
    # TODO: Sort subdirs
    for subdir in subdirs:
        if (subdir.startswith(".")):
            continue
        path = os.path.join(dir, subdir)
        example_file = os.path.join(path, "description.json")
        if (os.path.isfile(example_file)):
            example = addexample(path)
            if example is not None:
                category["examples"].append(example)
        else:
            subcategory = searchdir(path)
            if (subcategory is not None):
                category["categories"].append(subcategory)
    if (len(category["categories"]) + len(category["examples"]) > 0):
        return category
    return None

index = searchdir(".")
index["branch"] = get_git_branch()

with open(index_filename, "w") as index_file:
    json.dump(index, index_file, indent = 4)
