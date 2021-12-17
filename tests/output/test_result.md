# echo \\$USER
/Users/yuki/Documents/42cursus/minishell_shared/tests/output/diff_stdout
### bash result: 
> yuki
### minishell result: 
> \yuki

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
