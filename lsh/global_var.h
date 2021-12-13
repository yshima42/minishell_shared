#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include "execute.h"

char	*builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int	(*builtin_func[])(char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit,
};

#endif /* GLOBAL_VAR_H */
