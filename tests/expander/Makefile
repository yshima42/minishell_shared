NAME		= expander
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ../../expander/expand_var.c\
			  ../../expander/expand_var_all.c\
			  ../../expander/utils.c\
			  main.c\
			  ../../utils/utils.c\
			  ../../utils/shell_init.c\
			  ../../env/env_utils.c\
			  test/test_expand_var.c\
			  test/test_expand_var_all.c
			  # test/test_append_nonvar.c\
			  # test/test_search_prefix.c\
			  # test/test_strclen_array.c\

OBJS		= $(SRCS:.c=.o)
LIB_LEXER	= liblexer.a
L_SRC		= ../../lexer/tkn_lst.c\
			  ../../lexer/tkn_lstdel.c\
			  ../../lexer/tkn_strlen.c\
			  ../../lexer/lex_ctype.c\
			  ../../lexer/to_token.c\
			  ../lexer/test/test_to_token.c\
			  ../lexer/test/test_utils.c\
			  ../lexer/test/test_operator.c\
			  ../lexer/test/test_quote.c
L_SRCDIR	= ../lexer
L_SRCS		= $(addprefix ${L_SRCDIR}/,${L_SRC})
L_OBJS		= $(L_SRCS:.c=.o)

LIBS		= -L. -lft -L. -llexer -lreadline

all: $(NAME)

$(NAME): $(LIB_LEXER) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIB_LEXER): $(L_OBJS)
	ar -rc $(LIB_LEXER) $(L_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(L_OBJS)

fclean: clean
	rm -f $(LIB_LEXER)
	rm -f $(NAME)

re: fclean all

test: all
	./expander

# test_search_prefix: all
# 	./expander 0

test_expand_var: all
	./expander 1

# test_strclen_array: all
# 	./expander 2

# test_append_nonvar: all
# 	./expander 3

test_expand_all: all
	./expander 4

test_expand_exit_status: all
	./expander 5

.PHONY: all clean fclean re
