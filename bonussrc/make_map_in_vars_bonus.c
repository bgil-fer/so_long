/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_in_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:03:40 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 16:54:27 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_lines(char *file, t_vars *vars)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nError while opening the file\n");
		free_mem_struct(vars);
		close(fd);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		vars->rows++;
	}
	close(fd);
}

void	make_map_in_vars(t_vars *vars, int fd)
{
	int	i;

	i = 0;
	vars->map = (char **) ft_calloc((vars->rows + 1), sizeof(char *));
	vars->copy = (char **) ft_calloc((vars->rows + 1), sizeof(char *));
	if (!vars->map || !vars->copy)
	{
		free_mem_struct(vars);
		exit(1);
	}
	while (i < vars->rows)
	{
		vars->map[i] = get_next_line(fd);
		if (!vars->map[i])
			error(1, vars);
		vars->copy[i] = ft_strdup(vars->map[i]);
		i++;
	}
	vars->size_x = ft_strlen(vars->map[0]);
}
