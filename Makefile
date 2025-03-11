# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 10:07:29 by bgil-fer          #+#    #+#              #
#    Updated: 2025/03/11 18:29:15 by bgil-fer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME		=	so_long
NAME_BONUS	=	so_long_bonus

# Compilador y flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinclude -Ilib/minilibx-linux -Ilib/libft
#-g3 -fsanitize=address

# Directorios
SRCDIR		=	src
OBJDIR		=	obj
BONUSSRCDIR	=	bonussrc
BONUSOBJDIR	=	obj_bonus
LIBFTDIR	=	lib/libft
MLXDIR		=	lib/minilibx-linux

# Archivos fuente y objetos
# $(shell find $(SRCDIR) -name "*.c")
SRCS 	= 	src/main.c src/check_errors.c src/free_mem.c src/build_map.c src/render.c \
			src/check_route.c src/make_map_in_vars.c

SRC_BONUS = bonussrc/main_bonus.c bonussrc/check_errors_bonus.c bonussrc/free_mem_bonus.c \
			bonussrc/build_map_bonus.c bonussrc/render_bonus.c bonussrc/check_route_bonus.c \
			bonussrc/make_map_in_vars_bonus.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUSSRCDIR)/%.c, $(BONUSOBJDIR)/%.o, $(SRC_BONUS))

# Librerías
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
LIBS = -L$(MLXDIR) -lmlx -L$(LIBFTDIR) -lft -lXext -lX11 -lXrender -lm -lbsd

# Regla principal
all: $(NAME)

# Crear el directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilar los archivos fuente en objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilar la libft
$(LIBFT):
	make -C $(LIBFTDIR) -s

# Compilar MiniLibX
$(MLX):
	make -C $(MLXDIR) -s

# Enlazar el juego con las librerías
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) 

bonus: $(NAME_BONUS)

# Crear el directorio de objetos si no existe
$(BONUSOBJDIR):
	mkdir -p $(BONUSOBJDIR)

# Compilar los archivos fuente en objetos
$(BONUSOBJDIR)/%.o: $(BONUSSRCDIR)/%.c | $(BONUSOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Enlazar el juego con las librerías
$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS) $(LIBS)

# Limpiar archivos intermedios
clean:
	rm -rf $(OBJDIR) 
	rm -rf $(BONUSOBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

# Eliminar el ejecutable y objetos
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

# Recompilar desde cero
re: fclean all

re bonus: fclean all bonus

.PHONY: all bonus clean fclean re  re bonus