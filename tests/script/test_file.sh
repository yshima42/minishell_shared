#!/bin/bash

GRADEME_DIR=`pwd`

source ${GRADEME_DIR}/tests/script/test_base.sh

while read line
do
	tester $line
	printf "\n"
done < $1
