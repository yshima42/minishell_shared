# echo
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> 
### minishell result
---
# echo
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo a
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> a
### minishell result
---
# echo a
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo a
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo b
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> b
### minishell result
---
# echo b
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo b
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result
> yuki
### minishell result
---
# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# exit 0
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 0
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# exit 1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 1
### minishell result
> 127
---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit 2147483647
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 2147483647
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit 2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit 9223372036854775807
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 9223372036854775807
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: 9223372036854775808: numeric argument required
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 0
### minishell result
> 127
---
# exit -9223372036854775809
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: -9223372036854775809: numeric argument required
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -9223372036854775809
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 42
### minishell result
> 127
---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 42
### minishell result
> 127
---
# exit -- -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: --: numeric argument required
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit -- -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit --42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: --42: numeric argument required
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit --42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
# exit ++42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result
> minishell: exit: ++42: numeric argument required
### minishell result
> /Users/yuki/Documents/42cursus/minishell_shared/tests/script/test_base.sh: line 78: ./minishell: No such file or directory
---
# exit ++42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result
> 255
### minishell result
> 127
---
