# exit -- 42
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result
### minishell result
> minishell: exit: --: numeric argument required
---
# exit -- 42
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result
> 42
### minishell result
> 255
---
# exit 0 0; echo "this message should not be displayed" 2> file; ls
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result
> minishell: exit: too many arguments
### minishell result
> minishell: exit: too many arguments
---
