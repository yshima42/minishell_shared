#include "all.h"

int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	execvp(argv[2], &argv[2]);
	return 0;
}
