NAME		= lexer
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c\
			  ../../lexer/tkn_lst.c\
			  ../../lexer/tkn_lstdel.c\
			  ../../lexer/tkn_strlen.c\
			  ../../lexer/lex_ctype.c\
			  ../../lexer/to_token.c\
			  test/test_to_token.c\
			  test/test_utils.c\
			  test/test_operator.c\
			  test/test_quote.c
OBJS		= $(SRCS:.c=.o)
LIBS		= -L. -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(TEST_OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./lexer

test_operator: all
	./lexer 0

test_quote: all
	./lexer 1

test_strndup: all
	./lexer 2

.PHONY: all clean fclean re
