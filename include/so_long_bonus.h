/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:46:36 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/24 10:47:11 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#ifndef PX
	#define PX 80
#endif

enum
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	ORANGE = 0xff7f00
};

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	void	*p;
	void	*c;
	void	*e;
	void	*f;
	void	*w;
	void	*pe;
	void	*m;
	void	*g_o;
	void	*winn;
	int		collectable;
	int		player_x;
	int		player_y;
	int		exit;
	int		exit_x;
	int		exit_y;
	char	**map;
	int		rows;
	char 	**copy;
	int		size_x;
	int		size_y;
	int		movements;
	char	*move;
}				t_vars;

int		close_window(t_vars *vars);
void	error(int code, t_vars *vars);
void	check_filetype(char *filename, t_vars *vars);
void	check_walls(char *line,  int intermidiate_line, t_vars *vars);
void	check_player_exit_collectable(char **map, t_vars *mlx);
void	check_size(char **map, t_vars *vars);
void	check_char(char **map, t_vars *vars);
void	check_if_route_exists(char **map, t_vars *vars);
void	check_map(t_vars *mlx, char *file);
void	free_mem_struct(t_vars *vars);
void	build_map(t_vars *vars);
int		keys(int key, t_vars *v);
int		valid_movement(t_vars *v, int x, int y);
void	draw_map(t_vars *v);
void	render_images(t_vars *v);
void	make_map_in_vars(t_vars *vars, int fd);
void	check_filetype(char *filename, t_vars *vars);
void	count_lines(char *file, t_vars *vars);
void	winner(t_vars *v);
void	touching_enemy(t_vars *v);
void	fill_map(t_vars *v, int i, int j);

#endif