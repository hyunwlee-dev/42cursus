CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCSDIR_GNL = ./srcs/gnl/
SRCSDIR_PARSE = ./srcs/parsing/
SRCSDIR_QUEUE = ./srcs/queue/
SRCSDIR_RAYCAST = ./srcs/raycasting/

LIBFT_ARCHIVE = ./srcs/libft/libft.a

INCLUDES = -I ./includes -I ./mlx_opengl

FILE_GNL =	get_next_line \
			get_next_line_utils

FILE_PARSE =	check_identities \
				check_textures \
				check_floor_ceil \
            	check_map \
            	parse_identities \
            	parse_map \
            	parse_utils

FILE_QUEUE =	queue

FILE_RAYCAST = 	raycast \
				raycast_sub \
				raycast_utils \
				raycast_utils_sub \
				event_handler \
				event_handler2 \
				load_texture \
				load_buf \
				draw

BUFFERSIZE = -D BUFFER_SIZE=42

NAME = cub3D

LIBFT_LIBFLAG = -L./srcs/libft

SRCS_GNL = $(addsuffix .c, $(addprefix $(SRCSDIR_GNL), $(FILE_GNL)))
SRCS_PARSE = $(addsuffix .c, $(addprefix $(SRCSDIR_PARSE), $(FILE_PARSE)))
SRC_QUEUE = $(addsuffix .c, $(addprefix $(SRCSDIR_QUEUE), $(FILE_QUEUE)))
SRC_RAYCAST = $(addsuffix .c, $(addprefix $(SRCSDIR_RAYCAST), $(FILE_RAYCAST)))

all : $(NAME)

$(NAME) : $(SRCS_GNL) $(SRCS_PARSE) $(SRC_QUEUE) $(SRC_RAYCAST)
	$(MAKE) -C ./srcs/libft all
	$(MAKE) -C ./mlx_opengl all
	$(CC) $(CFLAGS) -framework OpenGL -framework Appkit -lz ./mlx_opengl/libmlx.a ./main.c $^ $(LIBFT_ARCHIVE) $(INCLUDES) $(BUFFERSIZE) -o $(NAME)
clean :
	$(MAKE) -C ./srcs/libft clean
	$(MAKE) -C ./mlx_opengl clean

fclean :
	$(MAKE) -C ./srcs/libft fclean
	rm cub3D

re : clean fclean all

.PHONY : all clean fclean

