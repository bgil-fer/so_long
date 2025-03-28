/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:22:38 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/24 10:43:49 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_vars *v)
{
	int	i;
	int	j;

	i = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
			fill_map(v, i, j);
	}
	j = -1;
	while ((v->size_x - 1) != j++)
		mlx_put_image_to_window(v->mlx, v->win, v->f, j * PX, i * PX);
	mlx_string_put(v->mlx, v->win, PX, (v->size_y * PX) - 60, ORANGE, v->move);
}

static void	actualize_position(t_vars *v, int x, int y, int code)
{
	char	*move;

	if (code == 1)
	{
		v->map[v->player_y][v->player_x] = '0';
		v->player_y = y;
		v->player_x = x;
		v->map[y][x] = 'L';
	}
	else
	{
		if (v->player_x == v->exit_x && v->player_y == v->exit_y)
			v->map[v->player_y][v->player_x] = 'E';
		else
			v->map[v->player_y][v->player_x] = '0';
		v->player_y = y;
		v->player_x = x;
		v->map[y][x] = 'P';
	}
	v->movements++;
	move = ft_itoa(v->movements);
	free(v->move);
	v->move = ft_strjoin("Movements: ", move);
	ft_printf("Movements = %i\n", v->movements);
	free(move);
}

int	keys(int key, t_vars *v)
{
	int	new_y;
	int	new_x;

	new_x = v->player_x * PX;
	new_y = v->player_y * PX;
	if (key == KEY_ESC)
		close_window(v);
	else if (key == KEY_A || key == KEY_LEFT)
		new_x -= PX;
	else if (key == KEY_D || key == KEY_RIGHT)
		new_x += PX;
	else if (key == KEY_W || key == KEY_UP)
		new_y -= PX;
	else if (key == KEY_S || key == KEY_DOWN)
		new_y += PX;
	else
		return (0);
	if (valid_movement(v, new_x / PX, new_y / PX))
	{
		mlx_clear_window(v->mlx, v->win);
		draw_map(v);
	}
	return (0);
}

int	valid_movement(t_vars *v, int x, int y)
{
	if (v->map[y][x] != '1')
	{
		if (v->map[y][x] == 'C')
			v->collectable--;
		if (v->map[y][x] == 'E')
		{
			if (v->collectable != 0)
			{
				v->exit_x = x;
				v->exit_y = y;
				actualize_position(v, x, y, 1);
				return (1);
			}
			else
				winner(v);
		}
		if (v->map[y][x] == 'M')
			touching_enemy(v);
		actualize_position(v, x, y, 0);
		return (1);
	}
	return (0);
}

void	build_map(t_vars *vars)
{
	int	w;
	int	h;

	w = PX * vars->size_x;
	h = PX * (vars->size_y) - 40;
	render_images(vars);
	vars->win = mlx_new_window(vars->mlx, w, h, "so_long");
	draw_map(vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_key_hook(vars->win, keys, vars);
	mlx_loop(vars->mlx);
}
