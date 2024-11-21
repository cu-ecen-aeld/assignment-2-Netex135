#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
fi

if [ $# -ne 2 ]
	then 
		echo " usage: finder 'filename' 'string' "
		exit 1
fi



filesdir=$1
searchstr=$2


# yes this is not optimal at all and I should learn AWK, but it works. 
if [ -d $filesdir ]
	then
		numberOfFiles=$(ls -Ra ${filesdir} | grep -v -e '^\.\{1,2\}$' -e '^\./.\{1,\}$' | tr -s "\n" | wc -l)
		numberOfMatching=$(grep -Rl ${filesdir} -e "${searchstr}"  2>/dev/null | wc -l)
		numberOfFiles=$(($numberOfFiles-1))
		echo "The number of files are ${numberOfFiles} and the number of matching lines are ${numberOfMatching}"  
	else
		echo  "	${filesdir}: is not a directory"
		exit 1
fi

