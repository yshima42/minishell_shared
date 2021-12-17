#!/bin/bash

GRADEME_DIR=`pwd`

source ${GRADEME_DIR}/tests/script/test_base.sh

# clean file
echo -n > ${GRADEME_DIR}/tests/output/test_result.md

while read line
do
	tester $line
	printf "\n"
done < $1
