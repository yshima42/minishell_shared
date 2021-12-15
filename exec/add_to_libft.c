#include "../minishell.h"

int	xdup(int fd)
{
	int	ret;

	ret = dup(fd);
	if (ret == -1)
		xperror("dup2");
	return (ret);
}

//move to yoshie's file
int	proc_num_count(t_proc *head)
{
	int		num;
	t_proc	*p;

	if (!head)
		return (0);
	num = 0;
	p = head;
	while (p)
	{
		p = p->next;
		num++;
	}
	return (num);
}
