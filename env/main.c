#include "minishell.h"

int main(void)
{
	t_info	*info;

	info = shell_init();
	print_all_env(info->env);
	ft_dict_clear(info->env);
	free(info);
	return 0;
}

void	detect_leak(void)__attribute__((destructor));

void detect_leak(void)
{
	system("leaks -q a.out");
}
