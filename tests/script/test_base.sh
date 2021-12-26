#!/bin/bash

COLOR_RESET="\033[0m"
COLOR_GREEN="\033[32m"
COLOR_RED="\033[31m"
COLOR_YELLOW="\033[33m"

GRADEME_DIR=`pwd`
OUTPUT_DIR="${GRADEME_DIR}/tests/output"

STDOUT_BASH="${OUTPUT_DIR}/stdout_bash"
STDOUT_MINISHELL="${OUTPUT_DIR}/stdout_minishell"
STDERR_MINISHELL_TMP="${OUTPUT_DIR}/stderr_minishell_tmp"

STDERR_MINISHELL="${OUTPUT_DIR}/stderr_minishell"
STDERR_BASH="${OUTPUT_DIR}/stderr_bash"
STDERR_BASH_TMP="${OUTPUT_DIR}/stderr_bash_tmp"

EXIIT_STATUS_BASH="${OUTPUT_DIR}/exit_status_bash"
EXIT_STATUS_MINISHELL="${OUTPUT_DIR}/exit_status_minishell"

DIFF_STDOUT="${OUTPUT_DIR}/diff_stdout"
DIFF_STDERR="${OUTPUT_DIR}/diff_stderr"
DIFF_EXIT_STATUS="${OUTPUT_DIR}/diff_exit_status"

TEST_RESULT="${OUTPUT_DIR}/test_result.md"

error_file_save()
{	
	printf "# " >> ${TEST_RESULT}
	echo ${@:4} >> ${TEST_RESULT}
	echo $1 >> ${TEST_RESULT}
	echo "### bash result: " >> ${TEST_RESULT}

	cat $2 | while read line
	do
	printf "> " >> ${TEST_RESULT}
	echo $line >> ${TEST_RESULT}
	done
	
	echo "### minishell result: " >> ${TEST_RESULT}
	cat $3 | while read line
	do
	printf "> " >> ${TEST_RESULT}
	echo $line >> ${TEST_RESULT}
	done

	printf "\n---\n" >> ${TEST_RESULT}
}

file_print()
{
	cat $@ | while read line
	do
	echo $line
	done
}

diff_check()
{
	if [ $? -eq 0 ]; then
		printf "${COLOR_GREEN}"
		printf "[OK]${COLOR_RESET}\n"
	elif [ $? -eq 1 ]; then
		printf "${COLOR_RED}"
		printf "[NG]\n"
		file_print $1
		error_file_save $1 $2 $3 ${@:4}
		printf "${COLOR_RESET}"
	fi
}

remove_file()
{
	rm -rf perm ls
}

tester()
{
	TEST_CMD=$@

	echo $TEST_CMD | bash > ${STDOUT_BASH} 2> ${STDERR_BASH_TMP} ; echo $? > ${EXIIT_STATUS_BASH}
	remove_file
	./minishell -c "$TEST_CMD" > ${STDOUT_MINISHELL} 2> ${STDERR_MINISHELL_TMP} ; echo $? > ${EXIT_STATUS_MINISHELL}
	if [ $1 = "exit" ]; then
		sed -e /^exit/d ${STDERR_MINISHELL_TMP} > ${STDERR_MINISHELL}
	else
		cp ${STDERR_MINISHELL_TMP} ${STDERR_MINISHELL}
	fi

	printf "${COLOR_YELLOW}$TEST_CMD\n${COLOR_RESET}"
	#STDOUT
	printf "STDOUT:      "
	diff -s ${STDOUT_BASH} ${STDOUT_MINISHELL} > ${DIFF_STDOUT}
	diff_check ${DIFF_STDOUT} ${STDOUT_BASH} ${STDOUT_MINISHELL} $TEST_CMD

	#STDERR
	sed -e 's/bash: line [1-9]/minishell/g' ${STDERR_BASH_TMP} > ${STDERR_BASH}
	rm ${STDERR_BASH_TMP}
	rm ${STDERR_MINISHELL_TMP}
	printf "STDERR:      "
	diff -s ${STDERR_BASH} ${STDERR_MINISHELL} > ${DIFF_STDERR}
	diff_check ${DIFF_STDERR} ${STDERR_BASH} ${STDERR_MINISHELL} $TEST_CMD

	#EXIT STATUS
	printf "EXIT STATUS: "
	diff -s ${EXIIT_STATUS_BASH} ${EXIT_STATUS_MINISHELL} > ${DIFF_EXIT_STATUS}
	diff_check ${DIFF_EXIT_STATUS} ${EXIIT_STATUS_BASH} ${EXIT_STATUS_MINISHELL} $TEST_CMD

	rm ${STDOUT_MINISHELL} ${STDOUT_BASH} ${DIFF_STDOUT}
	rm ${STDERR_MINISHELL} ${STDERR_BASH} ${DIFF_STDERR}
	rm ${EXIT_STATUS_MINISHELL} ${EXIIT_STATUS_BASH} ${DIFF_EXIT_STATUS}
}

perm_tester()
{
	TEST_CMD=$@

	echo $TEST_CMD | bash > ${STDOUT_BASH} 2> ${STDERR_BASH_TMP} ; echo $? > ${EXIIT_STATUS_BASH}
	remove_file
	./minishell -c "$TEST_CMD" > ${STDOUT_MINISHELL} 2> ${STDERR_MINISHELL_TMP} ; echo $? > ${EXIT_STATUS_MINISHELL}
	if [ $1 = "exit" ]; then
		sed -e /^exit/d ${STDERR_MINISHELL_TMP} > ${STDERR_MINISHELL}
	else
		cp ${STDERR_MINISHELL_TMP} ${STDERR_MINISHELL}
	fi

	printf "${COLOR_YELLOW}$TEST_CMD\n${COLOR_RESET}"
	#STDOUT
	printf "STDOUT:      "
	diff -s ${STDOUT_BASH} ${STDOUT_MINISHELL} > ${DIFF_STDOUT}
	diff_check ${DIFF_STDOUT} ${STDOUT_BASH} ${STDOUT_MINISHELL} $TEST_CMD

	#STDERR
	sed -e 's/bash/minishell/g' ${STDERR_BASH_TMP} > ${STDERR_BASH}
	rm ${STDERR_BASH_TMP}
	rm ${STDERR_MINISHELL_TMP}
	printf "STDERR:      "
	diff -s ${STDERR_BASH} ${STDERR_MINISHELL} > ${DIFF_STDERR}
	diff_check ${DIFF_STDERR} ${STDERR_BASH} ${STDERR_MINISHELL} $TEST_CMD

	#EXIT STATUS
	printf "EXIT STATUS: "
	diff -s ${EXIIT_STATUS_BASH} ${EXIT_STATUS_MINISHELL} > ${DIFF_EXIT_STATUS}
	diff_check ${DIFF_EXIT_STATUS} ${EXIIT_STATUS_BASH} ${EXIT_STATUS_MINISHELL} $TEST_CMD

	rm ${STDOUT_MINISHELL} ${STDOUT_BASH} ${DIFF_STDOUT}
	rm ${STDERR_MINISHELL} ${STDERR_BASH} ${DIFF_STDERR}
	rm ${EXIT_STATUS_MINISHELL} ${EXIIT_STATUS_BASH} ${DIFF_EXIT_STATUS}
}

