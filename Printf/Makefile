CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
                print_c.c \
                print_s.c \
                print_nbr.c \
                print_hex.c \
                treat_to_hex.c \
                treat_precision.c \
                treat_width.c

NAME = libftprintf.a

INC = -I./libft

#OBJ_DIR = ./obj
#OBJ_NAME = $(SRCS:.c=.o)
#OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

#$(OBJ_DIR)/%.o: ./%.c
#    $(CC) $(CFLAGS) $(INC) -o $@ -c $<

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INC) -c $(SRCS)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft all
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean :
	$(MAKE) -C ./libft clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
