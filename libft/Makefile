NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strlen.c\
			ft_strlcpy.c ft_strlcat.c ft_bzero.c ft_memset.c\
			ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c\
			ft_atoi.c ft_calloc.c ft_strdup.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

B_SRC	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\

M_SRC	=	convert_file_to_vector.c\
			dict_addback.c\
			dict_clear.c\
			dict_delone.c\
			dict_new.c\
			dict_size.c\
			dict_to_array.c\
			free_vector.c\
			ft_lstsize_sizet.c\
			ft_strajoin.c\
			ft_strclen.c\
			ft_strcmp.c\
			ft_strjoin3.c\
			ft_strndup.c\
			ft_trijoin.c\
			ft_ulongtoa_base.c\
			ft_v_strchr.c\
			ft_xstrdup.c\
			xdup2.c\
			xfork.c\
			xmalloc.c\
			xperror.c\
			xpipe.c

G_SRCS	= gnl/get_next_line_before.c gnl/get_next_line_utils.c

SRCDIR	= subject/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)
B_SRCS	= $(addprefix $(SRCDIR), $(B_SRC))
B_OBJS	= $(B_SRCS:.c=.o)
M_SRCDIR=  myfunc/
M_SRCS	= $(addprefix $(M_SRCDIR), $(M_SRC))
M_OBJS	= $(M_SRCS:.c=.o)
G_OBJS	= $(G_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(B_OBJS) $(M_OBJS) $(G_OBJS)
	ar -rc $(NAME) $(OBJS) $(B_OBJS) $(M_OBJS) $(G_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS) $(M_OBJS) $(G_OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
