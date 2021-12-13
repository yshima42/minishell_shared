#include "all.h"

int main(void)
{
	FILE	*fp;
	char	buf[1024];

	/* fp = popen("ls -l *.c | wc", "r"); */
	fp = popen("ls -l *.c | cat", "r");
	fgets(buf, sizeof(buf), fp);
	printf("[buf]%s\n", buf);
	pclose(fp);
	return 0;
}
