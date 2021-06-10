# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 12:26:49 by tharchen          #+#    #+#              #
#    Updated: 2021/06/10 15:22:52 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	so_long

CC						=	clang
FLAGS					=	-Wall -Wextra -Werror -O3
# FLAGS					=	-Wall -Wextra -Werror -g3 -fsanitize=address

FLAGS_MLX				=	-L./$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
# FLAGS_MLX				=	-lmlx -framework OpenGL -framework AppKit

# *** HEADER MLX ************************************************************* #

MLX_PATH				=	minilibx_opengl/

HEADER_MLX_DIR			=	$(MLX_PATH)

HEADER_MLX_LIST			=	\
							mlx.h	\

HEADER_MLX				=	$(addprefix $(HEADER_MLX_DIR), $(HEADER_MLX_LIST))

MLX_LIB					=	$(addprefix $(MLX_PATH), libmlx.a) # opengl

# *** PROJECT HEADER ********************************************************* #

HEADER_DIR				=	includes/

HEADER_LIST				=	\
							so_long.h \
							graphic_server.h \
							utils.h \
							color_shell.h \

HEADER					=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

# *** SRCS ******************************************************************* #

SRCS_DIR				=	srcs/

SRCS_LIST				=	\
							ft_memcpy.c \
							ft_strcmp.c \
							ft_strcpy.c \
							ft_strdel.c \
							ft_strdup.c \
							ft_strfind.c \
							ft_strjoin.c \
							ft_strlen.c \
							ft_strncpy.c \
							ft_strsub.c \
							gnl.c \
							ft_putnbr.c \
							main.c \
							hooks.c \
							draw.c \
							move.c \
							init_tiles.c \
							init_map.c \
							try_malloc.c \

SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# *** OBJS ******************************************************************* #

OBJS_DIR			=	objs/

OBJS_LIST			=	$(patsubst %.c, %.o, $(SRCS_LIST))

OBJS				=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# *** RULES ****************************************************************** #

.PHONY: initmlx clean fclean all re norm

all: gen initmlx $(NAME)

$(NAME): $(HEADER) $(SRCS) $(OBJS)
	@ $(CC) $(FLAGS) $(FLAGS_MLX) -I $(HEADER_DIR) $(OBJS) -o $@ $(MLX_LIB) -I $(HEADER_MLX_DIR)
	@ printf "\033[31m Program \033[32m%s : \033[34mCompilation \033[36m%-30s\033[0m\n" $(NAME) "done !"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(OBJS_DIR)
	@ $(CC) $(FLAGS) -I $(HEADER_DIR) -c -o $@ $< -I $(HEADER_MLX_DIR)
	@ printf "\033[31m Program \033[32m%s : \033[34mCompilation of \033[36m%-30s\033[0m\r" $(NAME) $(notdir $<)

initmlx:
	@ make -C $(MLX_PATH)

gen:
	@ $(CC) $(FLAGS) genmap.c -o genmap -O3

norm:
	@ norminette $(SRCS) $(HEADER)

clean:
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f genmap

re: fclean
	@ make -j
