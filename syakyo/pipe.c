#include "all.h"

int main(void)
{
	int		p_fd[2], nbytes;
	char	buf[1024];

	if (pipe(p_fd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	write(p_fd[1], "Hello\n", 6);
	nbytes = read(p_fd[0], buf, sizeof(buf));
	write(STDOUT_FILENO, buf, nbytes);
	close(p_fd[0]);
	close(p_fd[1]);
	return 0;
}
