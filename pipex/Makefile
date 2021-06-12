CC = gcc
CFLAGS = -Wall -Wextra -Werror
ASAN = -g3 -fsanitize=address

SRCS_DIR = ./srcs/
SRCS_NAME = check_validation.c \
			redirection.c \
			main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

INCLUDES = -I./includes -I./libs/libft

LIBFT_DIR = ./libs/libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)lib$(LIBFT_NAME).a

NAME = pipex

.PHONY : all clean fclean re

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean :
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re : clean fclean all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -L$(LIBFT_DIR) -l$(LIBFT_NAME) $^ -o $@ $(ASAN)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) bonus

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@
