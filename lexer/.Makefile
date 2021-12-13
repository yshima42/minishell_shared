NAME		= lexer
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c\
			  tkn_list.c\
			  tkn_strlen.c\
			  utils.c\
			  lex_ctype.c\
			  to_token.c
			  # test/test_lexer.c\
			  # test/test_utils.c
OBJS		= $(SRCS:.c=.o)
TEST_DIR	= ./test
TEST_FILES	= test_lexer.c\
			  test_utils
TEST_SRCS	= $(addprefix ${TEST_DIR}/,${TEST_FILES})
TEST_OBJS	= $(TEST_SRCS:.c=.o)
LIBS		= -L. -lft

all: $(NAME)

$(NAME): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(TEST_OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./lexer

test_operator: all
	./lexer 0

test_quote: all
	./lexer 1

.PHONY: all clean fclean re
