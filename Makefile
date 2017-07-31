# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 00:43:30 by rlecart           #+#    #+#              #
#    Updated: 2017/07/31 20:06:09 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	RTV1
NAME		=	rtv1
BINDIR		=	bin/
SRCDIR		=	src/
SRC			=	main.c \
				init.c \
				get.c \
				get_camera.c \
				get_cones.c \
				get_cylinders.c \
				get_planes.c \
				get_spheres.c \
				get_spots.c \
				hook.c \
				draw_cone.c \
				draw_cylinder.c \
				draw_obj.c \
				draw_plane.c \
				draw_sphere.c
MINILIBX	=	minilibx_macos/libmlx.a
LIBFT		=	libft/libft.a
GRAPHICS	=	graphics/graphics.a
OBJ			=	$(addprefix $(BINDIR),$(SRC:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -I libft/includes/ -I graphics/includes/
OPTI		=	-O2 -Ofast -O3
DEBUG		=	-fsanitize=address -g
MLXF		=	-framework OpenGL -framework AppKit

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: mlx lib gra $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(GRAPHICS) $(BINDIR) $(OBJ)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(MLXF) -o $(NAME) $(OBJ) $(MINILIBX) $(LIBFT) $(GRAPHICS) -g $(DEBUG)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@ -g                                                          \r"
	@$(CC) $(CFLAGS) -o $@ -c $< $(DEBUG)

mlx:
	@printf "$(YELLOW)[MINILIBX] Compiling bin...                                                     \r$(NO_COLOR)"
	@make -s -C minilibx_macos 2> /dev/null > /dev/null

lib:
	@make -s -C libft 2> /dev/null > /dev/null

gra:
	@make -s -C graphics 2> /dev/null > /dev/null

$(BINDIR):
	@mkdir bin

clean:
	@make -s -C libft clean
	@make -s -C graphics clean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"

fclean:
	@make -s -C minilibx_macos clean
	@make -s -C libft fclean
	@make -s -C graphics fclean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                               \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
