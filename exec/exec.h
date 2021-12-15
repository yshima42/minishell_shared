#ifndef EXEC_H
# define EXEC_H

//shell_ecec
int	exec_shell(t_proc *proc, t_info *info);

//exec_builtin.c
int	exec_builtin(t_proc *proc, t_info *info);
bool	is_builtin(char **args);

//exec_echo.c
int	exec_echo(char **args, t_info *info);

//loop_shell.c
void	loop_shell(t_info *info);
char	**shell_split_line(char *line);
bool	launch_shell(t_proc *proc, t_info *info);

//exec_shell.c
void	redirect_pipe(t_io *io_info, t_info *info);
void	save_stdfd(t_info *info);

#endif