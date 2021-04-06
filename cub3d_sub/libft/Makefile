CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strtrim.c

BONUS_F = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(FILES:.c=.o)
BONUS_O = $(BONUS_F:.c=.o)

NAME = libft.a

all : $(NAME)

%.o : %.c
	$(CC) -c $< $(CFLAGS)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)

bonus : $(BONUS_O)
	ar rcs $(NAME) $(BONUS_O)

clean :
	rm -f $(OBJS) $(BONUS_O)

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
