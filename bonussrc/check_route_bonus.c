/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:02:39 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 16:53:59 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_on_paths(int x, int y, t_vars *vars)
{
	char		type;
	static int	c;

	type = vars->copy[y][x];
	if (type == 'C')
	{
		c++;
		vars->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		vars->exit--;
		vars->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		vars->copy[y][x] = '1';
	else
		return (c);
	move_on_paths(x + 1, y, vars);
	move_on_paths(x - 1, y, vars);
	move_on_paths(x, y + 1, vars);
	move_on_paths(x, y - 1, vars);
	return (c);
}

void	check_if_route_exists(char **map, t_vars *vars)
{
	unsigned int	i;
	unsigned int	j;
	int				c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				break ;
			j++;
		}
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	vars->player_y = i;
	vars->player_x = j;
	c = move_on_paths(vars->player_x, vars->player_y, vars);
	if (vars->collectable != c || vars->exit != 0)
		error(5, vars);
}
