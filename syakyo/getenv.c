#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%s\n", getenv("HOME"));
	printf("%s\n", getenv("PATH"));;
	return 0;
}
