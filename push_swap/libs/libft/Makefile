CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

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

ifdef WITH_BONUS
	REAL_OBJECTS = $(OBJS) $(BONUS_O)
else
	REAL_OBJECTS = $(OBJS)
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_O)

fclean :
	rm -f $(NAME)

re : clean fclean all

bonus : $(BONUS_O)
	@$(MAKE) WITH_BONUS=1 all

$(NAME) : $(REAL_OBJECTS)
	ar -rcs $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
