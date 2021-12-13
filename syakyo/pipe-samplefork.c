#include "all.h"

int main(void)
{
	pid_t   pid;
	pid_t   wpid;
	int     status;
	int		p_fd[2], nbytes;
	char	buf[1024];

	if (pipe(p_fd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0) {
		exit(0);
	} else if (pid == 0) {
		close(p_fd[1]);
		nbytes = read(p_fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, nbytes);
		close(p_fd[0]);
	} else {
		close(p_fd[0]);
		write(p_fd[1], "Hello\n", 6);
		close(p_fd[1]);
		wpid = wait(&status);
	}
	return 0;
}
