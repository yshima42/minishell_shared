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
LEXER_PATH		=	./lexer/
PARSER_PATH		=	./parser/
EXPANDER_PATH	=	./expander/
HEREDOC_PATH	=	./heredoc/
SIGNAL_PATH		=	./signal/
EXEC_PATH		=	./exec/
BUILTIN_PATH	=	./builtin/
ENV_PATH		=	./env/
UTILS_PATH		=	./utils/
MAIN			=	main.c

LEXER_FILES		=	tkn_lst.c\
					tkn_lstdel.c\
					tkn_strlen.c\
					lex_ctype.c\
					to_token.c
PARSER_FILES	=	parse_line.c\
					to_proclist.c\
					split_expanded_word.c\
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
EXPANDER_FILES	=	expand_var.c\
					expand_var_all.c\
					utils.c
HEREDOC_FILES	=	heredoc_handler.c\
					heredoc_utils.c
SIGNAL_FILES	=	signal.c\
					signal_heredoc.c
EXEC_FILES    	= 	exec_bool.c\
					ft_exec.c\
					ft_exec_utils.c\
					ft_open.c\
					loop_shell.c\
					multi_procs.c\
					redirect_utils.c\
					single_proc.c
BUILTIN_FILES  	=	exec_builtin.c\
					exec_cd.c\
					cd_utils1.c\
					cd_utils2.c\
					exec_echo.c\
					exec_exit.c\
					exec_export.c\
					exec_unset.c\
					export_utils.c\
					utils.c
UTILS_FILES	=		utils.c\
					error.c\
					shell_init.c\
					shell_terminate.c 
ENV_FILES    	=	env_utils.c
BONUS_FILES		=
TEST_MAIN    	= 	$(TEST_PATH)/test_main.c $(TEST_PATH)/test_pipe.c
SRCS			= 	$(SRCS_FILES)
B_SRCS			= 	$(addprefix $(BONUS_PATH), $(BONUS_FILES))
LEXER_SRCS		= 	$(addprefix $(LEXER_PATH), $(LEXER_FILES))
PARSER_SRCS		= 	$(addprefix $(PARSER_PATH), $(PARSER_FILES))
EXPANDER_SRCS	= 	$(addprefix $(EXPANDER_PATH), $(EXPANDER_FILES))
HEREDOC_SRCS	= 	$(addprefix $(HEREDOC_PATH), $(HEREDOC_FILES))
SIGNAL_SRCS		= 	$(addprefix $(SIGNAL_PATH), $(SIGNAL_FILES))
UTILS_SRCS		= 	$(addprefix $(UTILS_PATH), $(UTILS_FILES))
EXEC_SRCS		= 	$(addprefix $(EXEC_PATH), $(EXEC_FILES))
BUILTIN_SRCS	= 	$(addprefix $(BUILTIN_PATH), $(BUILTIN_FILES))
ENV_SRCS		= 	$(addprefix $(ENV_PATH), $(ENV_FILES))
SRCS_OBJS		= 	$(MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o) $(SIGNAL_SRCS:.c=.o) $(EXPANDER_SRCS:.c=.o) $(HEREDOC_SRCS:.c=.o) $(UTILS_SRCS:.c=.o) $(EXEC_SRCS:.c=.o) $(BUILTIN_SRCS:.c=.o) $(ENV_SRCS:.c=.o)
TEST_OBJS		= 	$(TEST_MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o) $(SIGNAL_SRCS:.c=.o) $(EXPANDER_SRCS:.c=.o) $(HEREDOC_SRCS:.c=.o) $(UTILS_SRCS:.c=.o) $(EXEC_SRCS:.c=.o) $(BUILTIN_SRCS:.c=.o) $(ENV_SRCS:.c=.o)
# TEST_OBJS		=	$(TEST_MAIN:.c=.o) $(SRCS:.c=.o) $(PARSER_SRCS:.c=.o) $(LEXER_SRCS:.c=.o) $(SIGNAL_SRCS:.c=.o) $(EXPANDER_SRCS:.c=.o)
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
				# $(RM) $(NAME) $(BONUS_NAME) $(TEST_NAME) $(SRCS_OBJS) $(BONUS_PATH)$(BONUS_OBJS) $(BONUS_PATH)$(TEST_OBJS)

re:				fclean all

test:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/cases.txt

cd:				$(NAME)
				./tests/script/test_file.sh ./tests/cases/cd.txt

echo:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/echo.txt

env_test:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/env.txt

exit:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/exit.txt

expand:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/expand.txt

export:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/export.txt

pwd:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/pwd.txt

redirect:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/redirect.txt
				rm -rf file *.txt f out

shlvl:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/shlvl.txt

syntax:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/syntax_error.txt

simple:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/simple_command.txt
				rm -rf aa ab ac a .a perm dir ls 

unset:			$(NAME)
				./tests/script/test_file.sh ./tests/cases/unset.txt

permisson:		$(NAME)
				./tests/script/test_file.sh ./tests/cases/permission.txt

#pipe_test: 		$(TEST_OBJS)
#				$(LIBFTMAKE)
#				$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFTFLAG) -o $(TEST_NAME)
#				./tests 1

#bonus:			$(NAME) $(BONUS_OBJS)
#				$(LIBFTMAKE)
# 				$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFTFLAG) -o $(BONUS_NAME)

.PHONY:			all clean fclean bonus lib re
