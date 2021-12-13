NAME		= expander
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c\
			  expand_env_var.c\
			  test/test_search_prefix.c\
			  test/test_expand_var.c\
			  test/test_expand_var_all.c\
			  test/test_strclen_array.c\
			  test/test_append_nonvar.c

OBJS		= $(SRCS:.c=.o)
LIB_LEXER	= liblexer.a
L_SRC		= tkn_lst.c\
			  tkn_lstdel.c\
			  tkn_strlen.c\
			  utils.c\
			  lex_ctype.c\
			  to_token.c\
			  test/test_lexer.c\
			  test/test_utils.c
L_SRCDIR	= ../lexer
L_SRCS		= $(addprefix ${L_SRCDIR}/,${L_SRC})
L_OBJS		= $(L_SRCS:.c=.o)
LIB_ENV		= libenv.a
E_SRC		= shell_init.c\
			  env_utils.c\
			  utils.c
E_SRCDIR	= ../env
E_SRCS		= $(addprefix ${E_SRCDIR}/,${E_SRC})
E_OBJS		= $(E_SRCS:.c=.o)

LIBS		= -L. -lft -L. -llexer

all: $(NAME)

$(NAME): $(LIB_LEXER) $(OBJS) $(E_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(E_OBJS) $(LIBS)

$(LIB_LEXER): $(L_OBJS)
	ar -rc $(LIB_LEXER) $(L_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(E_OBJS)
	rm -f $(L_OBJS)

fclean: clean
	rm -f $(LIB_LEXER)
	rm -f $(NAME)

re: fclean all

test: all
	./expander

test_search_prefix: all
	./expander 0

test_expand_var: all
	./expander 1

test_strclen_array: all
	./expander 2

test_append_nonvar: all
	./expander 3

test_expand_all: all
	./expander 4

.PHONY: all clean fclean re
