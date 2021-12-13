#include<all.h>
enum {
	SIZE = 1024 * 1024,
};

int main(void)
{
	int		pfd[2], nbytes;
	char	buf[SIZE], buf2[SIZE];
	pipe(pfd);
	write(pfd[1], buf2, sizeof(buf2));
	nbytes = read(pfd[0], buf, sizeof(buf));
	close(pfd[0]);
	close(pfd[1]);
	
	return 0;
}
