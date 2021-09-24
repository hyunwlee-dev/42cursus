CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./srcs/
SRCSDIR_DEQUE = ./srcs/deque/
SRCSDIR_PUSH_SWAP_FUNC = ./srcs/push_swap_func/
SRCSDIR_SORT = ./srcs/sort/

FILE = main.c \
		utils.c

FILE_DEQUE = deque.c \
			 deque2.c \
			 deque_check.c \
			 deque_init.c \
			 deque_s.c \
			 deque_utils.c \
			 deque_utils2.c

FILE_PUSH_SWAP_FUNC = push_swap_func.c \
					  push_swap_func2.c \
					  push_swap_func3.c

FILE_SORT = sort.c \
			sort_check.c \
			sort_in_three_five.c \
			sort_in_three_five2.c \
			sort_quick.c \
			sort_utils.c

OBJS_DIR = ./objs/
SRCS = $(addprefix $(SRCSDIR), $(FILE))
OBJS = $(SRCS:.c=.o)
SRCS_DEQUE = $(addprefix $(SRCSDIR_DEQUE), $(FILE_DEQUE))
OBJS_DEQUE = $(SRCS_DEQUE:.c=.o)
SRCS_PUSH_SWAP_FUNC = $(addprefix $(SRCSDIR_PUSH_SWAP_FUNC), $(FILE_PUSH_SWAP_FUNC))
OBJS_PUSH_SWAP_FUNC = $(SRCS_PUSH_SWAP_FUNC:.c=.o)
SRCS_SORT = $(addprefix $(SRCSDIR_SORT), $(FILE_SORT))
OBJS_SORT = $(SRCS_SORT:.c=.o)

NAME = push_swap

INCLUDES := -I./includes/ -I./libs/libft

LIB_DIR = ./libs/libft/
LIB_NAME = ft
LIB = ./libs/libft/libft.a
LIBFT_LIBFLAG = -L./libs/libft -lft

NAME = push_swap

.PHONY : all clean fclean re

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJS) $(OBJS_DEQUE) $(OBJS_PUSH_SWAP_FUNC) $(OBJS_SORT)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME)

re : clean fclean all


$(NAME) : $(LIB) $(OBJS_DEQUE) $(OBJS_PUSH_SWAP_FUNC) $(OBJS_SORT)
	$(CC) $(CFLAGS) $(SRCS) $(SRCS_DEQUE) $(SRCS_PUSH_SWAP_FUNC) $(SRCS_SORT) $(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) -o $@

$(LIB) :
	make -C $(LIB_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@