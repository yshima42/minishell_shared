NAME		= parser
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c\
			  ../../parser/parse_line.c\
			  ../../parser/to_proclist.c\
			  ../../parser/remove_quote.c\
			  ../../parser/proc_lst.c\
			  ../../parser/proc_lstdel.c\
			  ../../parser/proc_ctype.c\
			  ../../parser/io_lst.c\
			  ../../parser/io_lstdel.c\
			  ../../parser/set_procinfo.c\
			  ../../parser/set_cmdinfo.c\
			  ../../parser/set_ioinfo.c\
			  ../../parser/validate_syntax.c\
			  test/test_count.c\
			  test/test_validate.c\
			  test/test_init.c\
			  test/test_set.c\
			  test/test_rm_quote.c\
			  test/test_count_quote.c\
			  test/utils_test.c\
			  test/test_parse_line.c\
			  ../../expander/expand_var.c\
			  ../../expander/expand_var_all.c\
			  ../../expander/utils.c\
			  ../../utils/utils.c\
			  ../../utils/shell_init.c\
			  ../../env/env_utils.c\
			  ../../heredoc/heredoc_handler.c\
			  ../../heredoc/heredoc_utils.c
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
L_OBJS		= $(L_SRC:.c=.o)
LIBS		= -L. -lft -L. -llexer

all: $(NAME)

$(NAME): $(LIB_LEXER) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIB_LEXER): $(L_OBJS)
	ar -rc $(LIB_LEXER) $(L_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB_LEXER)
	rm -f $(NAME)

re: fclean all

test: all
	./parser

test_countp: all
	./parser 1

test_validate: all
	./parser 2

test_init: all
	./parser 3

test_set: all
	./parser 4

test_remove: all
	./parser 5

test_countq: all
	./parser 6

test_remove_word: all
	./parser 7

test_parse_lines: all
	./parser 8

.PHONY: all clean fclean re
