/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:38:29 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 16:54:06 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_walls(char *l, int intermidiate_line, t_vars *vars)
{
	int	i;

	i = 0;
	if (intermidiate_line == 0)
	{
		while (l[i])
		{
			if (l[i] != '1')
				error(2, vars);
			i++;
		}
	}
	else
	{
		while (l[i])
		{
			if ((i == 0 && l[i] != '1') || (!(l[i + 1]) && l[i] != '1'))
				error(2, vars);
			i++;
		}
	}
}

void	check_player_exit_collectable(char **map, t_vars *vars)
{
	int	player;
	int	i;
	int	j;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				vars->exit++;
			else if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'C')
				vars->collectable++;
			j++;
		}
		i++;
	}
	if (vars->exit != 1 || player != 1 || vars->collectable < 1)
		error(4, vars);
}

void	check_size(char **map, t_vars *vars)
{
	int	i;

	i = 0;
	vars->size_y = vars->rows + 1;
	if (vars->size_y == vars->size_x)
		error(1, vars);
	if (vars->size_y < 3 || vars->size_x < 3)
		error(3, vars);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != vars->size_x)
			error(3, vars);
		i++;
	}
}

void	check_char(char **map, t_vars *vars)
{
	unsigned int	i;
	unsigned int	j;
	int				incorrect;

	check_walls(map[0], 0, vars);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			incorrect = 0;
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != 'P')
				incorrect++;
			if (map[i][j] != 'M' && incorrect == 1)
				incorrect++;
			if ((map[i][j] != 'C' && map[i][j] != '0') && incorrect == 2)
				error(6, vars);
			j++;
		}
		check_walls(map[i], 1, vars);
		i++;
	}
	check_walls(map[i - 1], 0, vars);
}

void	check_map(t_vars *vars, char *file)
{
	int		fd;

	check_filetype(file, vars);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nError opening the file\n");
		free_mem_struct(vars);
		exit (1);
	}
	count_lines(file, vars);
	make_map_in_vars(vars, fd);
	check_char(vars->map, vars);
	check_size(vars->map, vars);
	check_player_exit_collectable(vars->map, vars);
	check_if_route_exists(vars->map, vars);
	close(fd);
}
