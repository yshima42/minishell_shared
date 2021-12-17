CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	minishell
BONUS_NAME		= 	minishell_bonus
TEST_NAME		= 	tests
INCLUDES		= 	minishell.h
#SRCS_PATH		= 	./srcs/
BONUS_PATH		= 	./srcs_bonus/
LIBFT_PATH		= 	./libft/
TEST_PATH		=	./tests/
PARSER_PATH		=	./parser/
LEXER_PATH		=	./lexer/
EXPANDER_PATH	=	./expander/
SIGNAL_PATH		=	./signal/
MAIN			=	main.c
SRCS_FILES    	= 	exec/loop_shell.c exec/heredoc_handler.c \
					exec/redirect_utils.c exec/ft_exec.c exec/ft_xopen.c exec/single_proc.c exec/multi_procs.c\
					utils/utils.c builtin/exec_builtin.c builtin/exec_echo.c utils/shell_init.c builtin/exec_cd.c\
					builtin/exec_export.c env/env_utils.c builtin/exec_unset.c exec/exec_bool.c builtin/exec_exit.c builtin/utils.c builtin/export_utils.c
PARSER_FILES	=	parse_line.c\
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
					validate_syntax.c
LEXER_FILES		=	tkn_lst.c\
					tkn_lstdel.c\
					tkn_strlen.c\
					lex_ctype.c\
					to_token.c
SIGNAL_FILES	=	signal.c\
					signal_heredoc.c
EXPANDER_FILES	=	expand_var.c\
					expand_var_all.c\
					utils.c
BONUS_FILES		=
TEST_MAIN    	= 	$(TEST_PATH)/test_main.c $(TEST_PATH)/test_pipe.c
SRCS			= 	$(SRCS_FILES)
B_SRCS			= 	$(addprefix $(BONUS_PATH), $(BONUS_FILES))
PARSER_SRCS		= 	$(addprefix $(PARSER_PATH), $(PARSER_FILES))
LEXER_SRCS		= 	$(addprefix $(LEXER_PATH), $(LEXER_FILES))
EXPANDER_SRCS	= 	$(addprefix $(EXPANDER_PATH), $(EXPANDER_FILES))
SIGNAL_SRCS		= 	$(addprefix $(SIGNAL_PATH), $(SIGNAL_FILES))
SRCS_OBJS		= 	$(MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o) $(SIGNAL_SRCS:.c=.o) $(EXPANDER_SRCS:.c=.o)
TEST_OBJS		=	$(TEST_MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o) $(SIGNAL_SRCS:.c=.o) $(EXPANDER_SRCS:.c=.o)
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
				$(RM) $(NAME) $(BONUS_NAME) $(SRCS_OBJS) $(BONUS_PATH)$(BONUS_OBJS) $(BONUS_PATH)$(TEST_OBJS)

re:				fclean all

test:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/cases.txt

test_cd:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/cd.txt

test_echo:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/echo.txt

test_env:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/env.txt

test_exit:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/exit.txt

test_expand:	$(NAME)
				./tests/script/test_file.sh ./tests/cases/expand.txt

test_export:	$(NAME)
				./tests/script/test_file.sh ./tests/cases/export.txt

test_pwd:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/pwd.txt

test_redirect:	$(NAME)
				./tests/script/test_file.sh ./tests/cases/redirect.txt

test_syntax:	$(NAME)
				./tests/script/test_file.sh ./tests/cases/syntax_error.txt

test_unset:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/syntax_unset.txt

pipe_test: 		$(TEST_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFTFLAG) -o $(TEST_NAME)
				./tests 1

bonus:			$(NAME) $(BONUS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFTFLAG) -o $(BONUS_NAME)

.PHONY:			all clean fclean bonus lib re
