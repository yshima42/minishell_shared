#include "all.h"

int main(int argc, char* argv[])
{
	int		pfd[2];
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pfd[1], 1);
		close(pfd[0]);
		close(pfd[1]);
		execlp(argv[1], argv[1], (char *)NULL);
	}
	else
	{
		 /* wait(&status); */
		dup2(pfd[0], 0);
		close(pfd[0]);
		close(pfd[1]);
		execlp(argv[2], argv[2], (char *)NULL);
	}
	return 0;
}
