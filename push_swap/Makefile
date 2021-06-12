CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

INCLUDES = ./includes

SRCS_DIR = ./srcs/
SRCS_NAME = main.c

DEQUE_DIR = ./srcs/deque/
DEQUE_NAME = deque.c


SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
DEQUE_SRCS = $(addprefix $(DEQUE_DIR), $(DEQUE_NAME))

OBJS_DIR = ./objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
DEQUE_OBJS_NAME = $(DEQUE_NAME:.c=.o)

.PHONY all

all : $(NAME)

$(NAME) : $(SRCS) $(DEQUE_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $(NAME)

$(OBJS_DIR)%.o : $(DEQUE_SRCS)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $(NAME)


