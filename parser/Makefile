NAME		= parser
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c\
			  parse_line.c\
			  to_proclist.c\
			  remove_quote.c\
			  proc_lst.c\
			  proc_lstdel.c\
			  proc_ctype.c\
			  io_lst.c\
			  io_lstdel.c\
			  set_procinfo.c\
			  set_cmdinfo.c\
			  set_ioinfo.c\
			  validate_syntax.c\
			  test/test_count.c\
			  test/test_validate.c\
			  test/test_init.c\
			  test/test_set.c\
			  test/test_rm_quote.c\
			  test/test_count_quote.c\
			  test/utils_test.c
OBJS		= $(SRCS:.c=.o)
LIB_LEXER	= liblexer.a
L_SRC		= tkn_lst.c\
			  tkn_lstdel.c\
			  tkn_strlen.c\
			  lex_ctype.c\
			  to_token.c\
			  test/test_to_token.c\
			  test/test_utils.c\
			  test/test_operator.c\
			  test/test_quote.c
L_SRCDIR	= ../lexer
L_SRCS		= $(addprefix ${L_SRCDIR}/,${L_SRC})
L_OBJS		= $(L_SRCS:.c=.o)
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

.PHONY: all clean fclean re
