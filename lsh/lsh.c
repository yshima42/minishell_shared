#include "lsh.h"

static void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	do {
		printf("> ");
		line = lsh_readline_short();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
	return ;
}


int main(int argc, char* argv[])
{
	lsh_loop();
	return 0;
}
