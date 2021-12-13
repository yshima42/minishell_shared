#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv[])
{
	char	*line;

	line = NULL;
	while (true)
	{
		line = readline("\x1b[32mminishell\x1b[39m> ");
		if (line == NULL || strlen(line) == 0)
		{
			free(line);
			break ;
		}	
		printf("line is %s\n", line);
		add_history(line);
		free(line);
	}
	printf("exit\n");
	//rl_clear_history();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void	end(void)__attribute__((destructor));

void end(void)
{
	system("leaks -q a.out");
}
