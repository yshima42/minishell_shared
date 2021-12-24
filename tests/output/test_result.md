# exit -- 42
<<<<<<< HEAD
/Users/hyoshie/project/minish/tests/output/diff_stderr
=======
/Users/hyoshie/project/minish/share/tests/output/diff_stderr
>>>>>>> ad73e15... test:add STDERR_MINISHELL_TMP #3
### bash result: 
### minishell result: 
> minishell: exit: --: numeric argument required

---
# exit -- 42
/Users/hyoshie/project/minish/tests/output/diff_exit_status
### bash result: 
> 42
### minishell result: 
> 255

---
<<<<<<< HEAD
# exit 42 42
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
### minishell result: 
> 

---
# exit 0 0;
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
### minishell result: 
> 

---
# exit 0 0; exit;
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
### minishell result: 
> 

---
=======
>>>>>>> ad73e15... test:add STDERR_MINISHELL_TMP #3
# exit 0 0; echo "this message should not be displayed" 2> file; ls
/Users/hyoshie/project/minish/tests/output/diff_stderr
### bash result: 
> minishell: exit: too many arguments
### minishell result: 
> minishell: exit: too many arguments
<<<<<<< HEAD

---
# exit 0 0 | echo hello
/Users/hyoshie/project/minish/tests/output/diff_stdout
### bash result: 
> hello
### minishell result: 
> hello
> 

---
=======
> Makefile
> builtin
> env
> exec
> expander
> file
> heredoc
> lexer
> libft
> log
> logb
> loge
> logm
> main.c
> main.o
> minishell
> minishell.h
> parser
> ref
> signal
> tests
> utils

---
# exit 0 0; echo "this message should not be displayed" 2> file; ls
/Users/hyoshie/project/minish/share/tests/output/diff_exit_status
### bash result: 
> 1
### minishell result: 
> 0

---
>>>>>>> ad73e15... test:add STDERR_MINISHELL_TMP #3
