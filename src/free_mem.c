/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:05:08 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 15:00:42 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_mem(char **result)
{
	size_t	k;

	k = 0;
	if (!result || !(*result))
		return ;
	while (result[k])
	{
		free(result[k]);
		k++;
	}
	free(result);
}

void	free_mem_struct(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->map)
		free_mem(vars->map);
	if (vars->copy)
		free_mem(vars->copy);
	if (vars->p)
		mlx_destroy_image(vars->mlx, vars->p);
	if (vars->c)
		mlx_destroy_image(vars->mlx, vars->c);
	if (vars->e)
		mlx_destroy_image(vars->mlx, vars->e);
	if (vars->f)
		mlx_destroy_image(vars->mlx, vars->f);
	if (vars->w)
		mlx_destroy_image(vars->mlx, vars->w);
	if (vars->p_e)
		mlx_destroy_image(vars->mlx, vars->p_e);
	if (vars->mlx)
	{
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}
