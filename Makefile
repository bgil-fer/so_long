# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 10:07:29 by bgil-fer          #+#    #+#              #
#    Updated: 2025/03/11 16:09:13 by bgil-fer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = so_long

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -Ilib/minilibx-linux -Ilib/libft
#-g3 -fsanitize=address

# Directorios
SRCDIR = src
OBJDIR = obj
LIBFTDIR = lib/libft
MLXDIR = lib/minilibx-linux

# Archivos fuente y objetos
# $(shell find $(SRCDIR) -name "*.c")
SRCS 	= 	src/main.c src/check_errors.c src/free_mem.c src/build_map.c src/render.c \
			src/check_route.c src/make_map_in_vars.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

# Limpiar archivos intermedios
clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

# Eliminar el ejecutable y objetos
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re