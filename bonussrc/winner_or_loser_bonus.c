/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner_or_loser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:16:33 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:24 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	touching_enemy(t_vars *v)
{
	int	w;
	int	h;

	w = 794;
	h = 579;
	ft_printf("Ouch! You've dead\n");
	mlx_clear_window(v->mlx, v->win);
	v->g_o = mlx_xpm_file_to_image(v->mlx, "Images/loser.xpm", &w, &h);
	mlx_destroy_window(v->mlx, v->win);
	v->win = mlx_new_window(v->mlx, w, h, "Game over");
	mlx_hook(v->win, 17, 0, close_window, v);
	mlx_key_hook(v->win, keys, v);
	mlx_put_image_to_window(v->mlx, v->win, v->g_o, 0, 0);
	mlx_loop(v->mlx);
}

void	winner(t_vars *v)
{
	int	w;
	int	h;

	w = 794;
	h = 579;
	ft_printf("Congrats! You've won!\n");
	mlx_clear_window(v->mlx, v->win);
	v->g_o = mlx_xpm_file_to_image(v->mlx, "Images/winner.xpm", &w, &h);
	mlx_destroy_window(v->mlx, v->win);
	v->win = mlx_new_window(v->mlx, w, h, "Winner");
	mlx_hook(v->win, 17, 0, close_window, v);
	mlx_key_hook(v->win, keys, v);
	mlx_put_image_to_window(v->mlx, v->win, v->g_o, 0, 0);
	mlx_loop(v->mlx);
}
