# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
> yuki
### minishell result: 
> \yuki

---
# exit 0
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit 1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -1
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: -1: numeric argument required

---
# exit 2147483647
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit 2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: -2147483648: numeric argument required

---
# exit -2147483648
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 255

---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -2147483649
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: -2147483649: numeric argument required

---
# exit 9223372036854775807
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit 9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
> minishell: exit: 9223372036854775808: numeric argument required
### minishell result: 

---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: -9223372036854775808: numeric argument required

---
# exit -9223372036854775808
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result: 
> 0
### minishell result: 
> 255

---
# exit -9223372036854775809
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: --: numeric argument required

---
# exit -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result: 
> 42
### minishell result: 
> 255

---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stderr
### bash result: 
### minishell result: 
> minishell: exit: 42 : numeric argument required

---
# exit " 42 "
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_exit_status
### bash result: 
> 42
### minishell result: 
> 255

---
# exit -- -- 42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit --42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
# exit ++42
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
### minishell result: 
> exit

---
