NAME := philo

SRC_DIR = ./srcs/
SRC_NAME = main.c \
			init.c \
			routine.c \
			routine_sub.c \
			utils.c
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

CC := gcc
CFLAGS := -Wall -Wextra -Werror
INCLUDE := -I./includes

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY : all clean fclean re
