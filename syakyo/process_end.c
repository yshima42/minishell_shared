#include "all.h"

int main(void)
{
	pid_t   pid;
	pid_t   wpid;
	int     status;

	pid = fork();
	if (pid < 0) {
		exit(0);
	} else if (pid == 0) {
		printf("Child\n");
	} else {
		wpid = wait(&status);
		printf("\x1b[32mAfter Wait\x1b[39m\n");
	}
	sleep(2);
	printf("\x1b[31mLast\x1b[39m\n");
	return 0;
}
