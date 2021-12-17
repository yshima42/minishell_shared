#!/bin/bash

make

COLOR_RESET="\033[0m"
COLOR_GREEN="\033[32m"
COLOR_RED="\033[31m"

diff_check()
{
	if [ $? -eq 0 ]; then
		printf "${COLOR_GREEN}"
		printf "[OK]${COLOR_RESET}\n"
	elif [ $? -eq 1 ]; then
		printf "${COLOR_RED}"
		printf "[NG]${COLOR_RESET}\n"
		printf "see diff files\n"
	fi
}

tester()
{
	TEST_CMD=$1

	echo $TEST_CMD | bash > test/stdout_bash 2> test/stderr_bash_tmp 
	echo $? > test/exit_status_bash
	echo $TEST_CMD | ./minishell > test/stdout_minishell_tmp 2> test/stderr_minishell
	echo $? > test/exit_status_minishell

	printf "Case: $TEST_CMD\n"
	#STDOUT
	sed '/32mminishell/d' test/stdout_minishell_tmp > test/stdout_minishell
	rm test/stdout_minishell_tmp 
	printf "STDOUT: "
	diff -s test/stdout_bash test/stdout_minishell > test/diff_stdout
	diff_check

	#line 1を対応するかどうか要検討
	#STDERR
	sed -e 's/bash: line 1/minishell/g' test/stderr_bash_tmp > test/stderr_bash
	rm test/stderr_bash_tmp
	printf "STDERR: "
	diff -s test/stderr_bash2 test/stderr_minishell > test/diff_stderr
	diff_check

	#EXIT STATUS
	printf "EXIT STATUS: "
	diff -s test/exit_status_bash test/exit_status_minishell > test/diff_exit_status
	diff_check
}

while read line
do
	tester $line
	printf "\n"
done < test/case.txt
