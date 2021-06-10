NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -O3
SRC = ./srcs/ft_memcpy.c \
							./srcs/ft_strcmp.c \
							./srcs/ft_strcpy.c \
							./srcs/ft_strdel.c \
							./srcs/ft_strdup.c \
							./srcs/ft_strfind.c \
							./srcs/ft_strjoin.c \
							./srcs/ft_strlen.c \
							./srcs/ft_strncpy.c \
							./srcs/ft_strsub.c \
							./srcs/gnl.c \
							./srcs/ft_putnbr.c \
							./srcs/main.c \
							./srcs/hooks.c \
							./srcs/draw.c \
							./srcs/move.c \
							./srcs/init_tiles.c \
							./srcs/init_map.c \
							./srcs/try_malloc.c \

LIB = -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd
INC = -I . -I ./mlx-linux -I ./includes
OBJ = $(SRC:.c=.o)

OPTION = -L ./mlx-linux\
 

all: $(NAME)

$(NAME): $(SRC) ./includes/color_shell.h ./includes/graphic_server.h ./includes/so_long.h ./includes/utils.h
	@ $(CC) $(CFLAGS) $(SRC) $(OPTION) $(INC) $(LIB) -o $(NAME)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

gen:
	@ $(CC) $(FLAGS) genmap.c -o genmap

re: fclean all

.PHONY: all clean fclean re
