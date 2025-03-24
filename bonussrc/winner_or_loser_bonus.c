/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner_or_loser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:16:33 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/24 10:43:34 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	keys2(int key, t_vars *v)
{
	if (key == KEY_ESC)
		close_window(v);
	return (0);
}

void	touching_enemy(t_vars *v)
{
	int	w;
	int	h;

	w = 794;
	h = 579;
	v->movements++;
	ft_printf("Movements = %i\n", v->movements);
	ft_printf("Ouch! You've dead :(\n");
	mlx_clear_window(v->mlx, v->win);
	v->g_o = mlx_xpm_file_to_image(v->mlx, "Images/loser.xpm", &w, &h);
	mlx_destroy_window(v->mlx, v->win);
	v->win = mlx_new_window(v->mlx, w, h, "Game over");
	mlx_hook(v->win, 17, 0, close_window, v);
	mlx_key_hook(v->win, keys2, v);
	mlx_put_image_to_window(v->mlx, v->win, v->g_o, 0, 0);
	mlx_loop(v->mlx);
}

void	winner(t_vars *v)
{
	int	w;
	int	h;

	w = 794;
	h = 579;
	v->movements++;
	ft_printf("Movements = %i\n", v->movements);
	ft_printf("Congrats! You've won! :)\n");
	mlx_clear_window(v->mlx, v->win);
	v->g_o = mlx_xpm_file_to_image(v->mlx, "Images/winner.xpm", &w, &h);
	mlx_destroy_window(v->mlx, v->win);
	v->win = mlx_new_window(v->mlx, w, h, "Winner");
	mlx_hook(v->win, 17, 0, close_window, v);
	mlx_key_hook(v->win, keys2, v);
	mlx_put_image_to_window(v->mlx, v->win, v->g_o, 0, 0);
	mlx_loop(v->mlx);
}

void	fill_map(t_vars *v, int i, int j)
{
	if (v->map[i][j] == 'P')
		mlx_put_image_to_window(v->mlx, v->win, v->p, j * PX, i * PX);
	if (v->map[i][j] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->e, j * PX, i * PX);
	if (v->map[i][j] == 'C')
		mlx_put_image_to_window(v->mlx, v->win, v->c, j * PX, i * PX);
	if (v->map[i][j] == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->w, j * PX, i * PX);
	if (v->map[i][j] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->f, j * PX, i * PX);
	if (v->map[i][j] == 'L')
		mlx_put_image_to_window(v->mlx, v->win, v->pe, j * PX, i * PX);
	if (v->map[i][j] == 'M')
		mlx_put_image_to_window(v->mlx, v->win, v->m, j * PX, i * PX);
}
