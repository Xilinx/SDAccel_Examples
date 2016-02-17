#!/bin/bash

checkabortfailed() 
{
	if [ $1 -eq 0 ]
	then
	  echo "INFO: Step finished successfully"
	else
	  echo "ERROR: An error occurred. aborting..."
	  exit 1
	fi
}

get_cur_dir() {
	SOURCE="${BASH_SOURCE[0]}"
	
	# resolve $SOURCE until the file is no longer a symlink
	while [ -h "$SOURCE" ]; do 
	  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
	  SOURCE="$(readlink "$SOURCE")"
	  # if $SOURCE was a relative symlink, we need to resolve it relative to 
	  # the path where the symlink file was located
	  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" 
	done
	DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
}


if [ -z "$SDACCEL_ROOT" ]
then
	echo "WARNING: SDACCEL_ROOT is not defined. I will use which to find it."
	export SDACCEL_ROOT=`which sdaccel`
	checkabortfailed $?

	export SDACCEL_ROOT=$(dirname $SDACCEL_ROOT)
	export SDACCEL_ROOT=$(dirname $SDACCEL_ROOT)
	echo "INFO: detected SDAccel root at ${SDACCEL_ROOT}" 
fi

echo "INFO: SDACCEL_ROOT=${SDACCEL_ROOT}"

echo "INFO: Building kernel..."
sdaccel smithwaterman_hw_systolic.tcl
