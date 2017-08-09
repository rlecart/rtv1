# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 19:16:02 by bbeldame          #+#    #+#              #
#    Updated: 2017/08/09 15:05:48 by ocojeda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
FLAGS = -Wall -Wextra -Ofast# @todo : Add -Werror Flag, Uncomment Minilibx clean -Ofast
MLX = ./minilibX/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
LINKS = -L ./minilibX -lm -lmlx -framework OpenGL -framework AppKit
LIBVECA = libvec.a
LIBVECDIR = ./libvec
LIBFTA = libft.a
LIBFTDIR = ./libft
MLXA = ./miniLibX/libmlx.a
OBJDIR = ./objs/
INCDIR = ./includes
SRCDIR = ./srcs/
SRCS_NAME = color.c cone.c create_img.c main.c operation.c \
	ray.c raytrace.c sphere.c vector.c hooks.c plane.c \
	parsing/parse.c cylinder.c parsing/p_errors.c \
	parsing/p_objects.c parsing/p_setup.c parsing/p_utils.c \
	supersampler.c 
OBJS = $(SRCS_NAME:.c=.o)
OBJS := $(notdir $(OBJS))
OBJS := $(addprefix $(OBJDIR), $(OBJS))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))
LIBVEC = $(addprefix $(LIBVECDIR)/,$(LIBVECA))
VPATH = $(SRCDIR):$(SRCDIR)parsing

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
	@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -I $(LIBVECDIR) -I $(MLX) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFTDIR)

$(LIBVEC):
	@make -C $(LIBVECDIR)

$(MLXA):
	@make -sC $(MLX)

$(NAME): $(LIBFT) $(LIBVEC) $(MLXA) $(OBJDIR) $(OBJS)
	@gcc $(OBJS) $(LINKS) $(LIBFT) $(LIBVEC) -lm -o $(NAME)
	@echo "$(GREEN)----------RTv1 compiled-----------$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(LIBVECDIR)
#	@make --silent clean -C $(MLX)

fclean:	clean
	@rm -f $(NAME)
#	@make fclean -C $(LIBFTDIR)
	@echo "$(GREEN)-----RTv1 removed completely------$(NC)"

re: fclean all

.PHONY: all clean fclean re