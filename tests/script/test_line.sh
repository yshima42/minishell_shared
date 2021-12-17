#!/bin/bash

GRADEME_DIR=`pwd`

source ${GRADEME_DIR}/tests/script/test_base.sh
make
tester $@
