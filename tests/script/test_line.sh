#!/bin/bash

GRADEME_DIR=`pwd`

source ${GRADEME_DIR}/tests/script/test_base.sh
make
echo -n > ${GRADEME_DIR}/tests/output/test_result.md
tester $@
