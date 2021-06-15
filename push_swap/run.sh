# /bin/bash

gcc -Wall -Wextra -Werror ./srcs/main.c ./srcs/deque/deque.c ./srcs/push_swap_func.c ./libs/libft/libft.a -I ./includes -I ./libs/libft -o push_swap

