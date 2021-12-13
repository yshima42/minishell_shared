%{
#include <stdio.h>
%}

%%

[\t ]+ { /*do nothing*/ }

[0-9]+ { printf("digit = %s\n", yytext); }

[a-z]+ { printf("alphabet = %s\n", yytext); }

\n { /*do nothing*/ }

. { printf("Syntax error\n"); }

%%
