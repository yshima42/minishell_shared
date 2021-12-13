CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	minishell
BONUS_NAME		= 	minishell_bonus
TEST_NAME		= 	tests
INCLUDES		= 	minishell.h
#SRCS_PATH		= 	./srcs/
BONUS_PATH		= 	./srcs_bonus/
LIBFT_PATH		= 	./libft/
TEST_PATH		=	./test/
PARSER_PATH		=	./parser/
LEXER_PATH		=	./lexer/
MAIN			=	main.c
SRCS_FILES    	= 	exec/loop_shell.c exec/exec_shell.c utils/utils.c utils/tmp.c builtin/exec_builtin.c builtin/exec_echo.c env/shell_init.c \
					builtin/exec_export.c env/env_utils.c builtin/exec_unset.c utils/error.c utils/is.c
PARSER_FILES	=	to_proclist.c\
					remove_quote.c\
					parse_ctype.c\
					proc_lst.c\
					proc_lstdel.c\
					io_lst.c\
					io_lstdel.c\
					set_procinfo.c\
					set_cmdinfo.c\
					set_ioinfo.c\
					validate_syntax.c
LEXER_FILES		=	tkn_lst.c\
					tkn_lstdel.c\
					tkn_strlen.c\
					lex_ctype.c\
					to_token.c
BONUS_FILES		=
TEST_MAIN    	= 	$(TEST_PATH)/test_main.c $(TEST_PATH)/test_pipe.c
SRCS			= 	$(SRCS_FILES)
B_SRCS			= 	$(addprefix $(BONUS_PATH), $(BONUS_FILES))
PARSER_SRCS		= 	$(addprefix $(PARSER_PATH), $(PARSER_FILES))
LEXER_SRCS		= 	$(addprefix $(LEXER_PATH), $(LEXER_FILES))
SRCS_OBJS		= 	$(MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o)
TEST_OBJS		=	$(TEST_MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o)  
BONUS_OBJS		= 	$(SRCS:.c=.o)
LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft

ifeq ($(shell uname), Darwin)
	CFLAGS += -I$(shell brew --prefix readline)/include
	LIBFTFLAG += -L$(shell brew --prefix readline)/lib -lreadline
else
	LIBFTFLAG += -lreadline
endif

all:			$(NAME)

$(NAME):		$(SRCS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) -o $(NAME)

lib:
				$(LIBFTMAKE)

.c.o:
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(RM) $(SRCS_OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(RM) $(NAME) $(BONUS_NAME) $(TEST_NAME) $(SRCS_OBJS) $(BONUS_PATH)$(BONUS_OBJS) $(BONUS_PATH)$(TEST_OBJS)

re:				fclean all

test: 			$(TEST_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFTFLAG) -o $(TEST_NAME)

test_start: test
				./tests 0

test_pipe:
				./tests 1

bonus:			$(NAME) $(BONUS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFTFLAG) -o $(BONUS_NAME)

.PHONY:			all clean fclean bonus lib re