/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyoshie <hyoshie@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:14:27 by hyoshie           #+#    #+#             */
/*   Updated: 2022/01/05 18:57:24 by hyoshie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*replace_line(char *line, t_dict *env)
{
	char	*ret;

	ret = replace_var_in_str(line, env);
	free(line);
	return (ret);
}

static void	heredoc_child(t_token *tokens, t_dict *env, int heredoc_fd)
{
	char	*line;
	char	*delimiter;
	bool	expand;

	delimiter = remove_quoting_in_str(tokens->next->word);
	if (ft_strcmp(tokens->next->word, delimiter) == 0)
		expand = true;
	else
		expand = false;
	while (true)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		if (expand && line[0] != '\0')
			line = replace_line(line, env);
		ft_putendl_fd(line, heredoc_fd);
		free(line);
	}
	free(line);
	free(delimiter);
	exit(0);
}

static void	heredoc_wait_close(pid_t pid, int *status, int heredoc_fd)
{
	set_signal_ignore();
	xwaitpid(pid, status, 0);
	xclose(heredoc_fd);
}

int	store_heredoc(t_token *tokens, t_dict *env, int heredoc_fd)
{
	pid_t	pid;
	int		status;

	pid = xfork();
	if (pid == 0)
	{
		heredoc_child(tokens, env, heredoc_fd);
	}
	else
	{
		heredoc_wait_close(pid, &status, heredoc_fd);
		if (WEXITSTATUS(status) == HEREDOC_EXIT)
			return (HEREDOC_EXIT);
	}
	return (DEFAULT);
}
