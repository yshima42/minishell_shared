#ifndef EXECUTE_H
#define EXECUTE_H

/* int	lsh_num_builtins(); */
int	lsh_cd(char **args);
int	lsh_help(char **args);
int	lsh_exit(char **args);
/* int	lsh_launch(char **args); */
int	lsh_execute(char **args);

/* Function Declares for builtin shell commands */
/* char	*builtin_str[] = { */
/* 	"cd", */
/* 	"help", */
/* 	"exit" */
/* }; */

/* int	(*builtin_func[])(char **) = { */
/* 	&lsh_cd, */
/* 	&lsh_help, */
/* 	&lsh_exit, */
/* }; */

#endif /* EXECUTE_H */
