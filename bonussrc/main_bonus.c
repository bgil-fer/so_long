/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:44:36 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 19:58:47 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_vars *vars)
{
	free_mem_struct(vars);
	exit(0);
	return (0);
}

void	error2(int code)
{
	if (code == 11)
		ft_printf("\n");
}

void	error(int code, t_vars *vars)
{
	ft_printf("Error\n");
	if (code == 1)
		ft_printf("You cannot use a square as a map\n");
	else if (code == 2)
		ft_printf("The edges of the rectangle must be walls\n");
	else if (code == 3)
		ft_printf("The map is not a valid rectangle\n");
	else if (code == 4)
		ft_printf("Error in exit, player or collectable\n");
	else if (code == 5)
		ft_printf("There is not a possible route to get the objetive\n");
	else if (code == 6)
		ft_printf("Invalid character in the map\n");
	else if (code == 7)
		ft_printf("Use: ./so_long \"/Map/file.ber\"\n");
	else if (code == 8)
		ft_printf("The map is not in a file .ber\n");
	else if (code == 9)
		ft_printf("Memory usage error\n");
	else if (code == 10)
		ft_printf("Error while mounting images\n");
	else
		error2(code);
	free_mem_struct(vars);
	exit(1);
}

void	inicialize_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->copy = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->rows = 0;
	vars->size_y = 0;
	vars->size_x = 0;
	vars->exit = 0;
	vars->collectable = 0;
	vars->movements = 0;
	vars->exit_x = 0;
	vars->exit_y = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->p = NULL;
	vars->c = NULL;
	vars->e = NULL;
	vars->f = NULL;
	vars->w = NULL;
	vars->p_e = NULL;
	vars->m = NULL;
	vars->g_o = NULL;
	vars->winn = NULL;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	inicialize_vars(&vars);
	if (argc != 2)
		error(7, &vars);
	vars.mlx = mlx_init();
	check_map(&vars, argv[1]);
	build_map(&vars);
	return (0);
}
