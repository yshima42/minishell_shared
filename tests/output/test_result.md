# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> yuki
### minishell result
> \yuki
---
# exit 0
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit 1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: -1: numeric argument required
---
# exit 2147483647
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit 2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: -2147483648: numeric argument required
---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 255
---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: -2147483649: numeric argument required
---
# exit 9223372036854775807
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: 9223372036854775808: numeric argument required
### minishell result
---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: -9223372036854775808: numeric argument required
---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 255
---
# exit -9223372036854775809
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: --: numeric argument required
---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 42
### minishell result
> 255
---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: 42 : numeric argument required
---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 42
### minishell result
> 255
---
# exit -- -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit --42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# exit ++42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
### minishell result
> exit
---
# ls -la
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> total 120
> drwxr-xr-x 24 yuki staff 768 Dec 17 22:17 .
> drwxr-xr-x@ 28 yuki staff 896 Dec 17 20:33 ..
> drwxr-xr-x 15 yuki staff 480 Dec 17 19:09 .git
> -rw-r--r-- 1 yuki staff 445 Dec 17 09:38 .gitignore
> drwxr-xr-x 3 yuki staff 96 Dec 17 14:40 .heredoc
> -rw-r--r-- 1 yuki staff 3014 Dec 17 21:30 Makefile
> -rw-r--r-- 1 yuki staff 77 Dec 17 09:38 README.md
> -rw-r--r-- 1 yuki staff 0 Dec 17 22:15 a
> drwxr-xr-x 10 yuki staff 320 Dec 17 22:17 builtin
> drwxr-xr-x 6 yuki staff 192 Dec 17 22:17 env
> drwxr-xr-x 11 yuki staff 352 Dec 17 22:17 exec
> drwxr-xr-x 11 yuki staff 352 Dec 17 22:17 expander
> drwxr-xr-x 15 yuki staff 480 Dec 17 22:17 lexer
> drwxr-xr-x 7 yuki staff 224 Dec 17 22:17 libft
> -rw-r--r-- 1 yuki staff 1250 Dec 17 09:38 main.c
> -rw-r--r-- 1 yuki staff 1301 Dec 17 21:28 minishell.h
> drwxr-xr-x 20 yuki staff 640 Dec 17 22:17 parser
> drwxr-xr-x 5 yuki staff 160 Dec 17 09:38 script
> drwxr-xr-x 6 yuki staff 192 Dec 17 22:17 signal
> -rw-r--r-- 1 yuki staff 33087 Dec 17 09:38 tags
> drwxr-xr-x 10 yuki staff 320 Dec 17 21:14 tests
> -rw-r--r-- 1 yuki staff 1280 Dec 17 09:38 typescript
> drwxr-xr-x 5 yuki staff 160 Dec 17 22:17 utils
> drwxr-xr-x 12 yuki staff 384 Dec 17 14:42 workspace
### minishell result
---
# ls -la
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# ls -la
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
