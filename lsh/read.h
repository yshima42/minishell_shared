#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LSH_RL_BUFSIZE 1024

char	*lsh_readline_long(void);
char	*lsh_readline_short(void);

#endif /* READ_H */
