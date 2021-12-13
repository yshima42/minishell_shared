#include "all.h"

int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(fd, STDOUT_FILENO);
	execvp(argv[2],  &argv[2]);
	return 0;
}
