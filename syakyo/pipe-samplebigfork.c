#include "all.h"

enum {
	SIZE = 1024 * 1024,
};

int main(void)
{
	pid_t   pid;
	pid_t   wpid;
	int     status;
	int     n;
	int		pfd[2], nbytes;
	char	buf[SIZE], buf2[SIZE] = "Hello\n";

	pipe(pfd);
	pid = fork();
	if (pid < 0) {
		exit(0);
	} else if (pid == 0) {
		close(pfd[1]);
		while ((n = read(pfd[0], buf, sizeof(buf)))> 0)
			printf("%6sn = %d\n", buf, n);
		write(STDOUT_FILENO, buf, nbytes);
		close(pfd[0]);
	} else {
		close(pfd[0]);
		write(pfd[1], buf2, sizeof(buf2));
		close(pfd[1]);
		wpid = wait(&status);
	}
	return 0;
}
