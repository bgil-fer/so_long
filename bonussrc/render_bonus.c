/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:05:24 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 18:40:18 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_images(t_vars *v)
{
	int	w;
	int	h;

	w = PX;
	h = PX;
	v->p = mlx_xpm_file_to_image(v->mlx, "Images/p.xpm", &w, &h);
	if (!v->p)
		error(10, v);
	v->c = mlx_xpm_file_to_image(v->mlx, "Images/c.xpm", &w, &h);
	if (!v->c)
		error(10, v);
	v->e = mlx_xpm_file_to_image(v->mlx, "Images/e.xpm", &w, &h);
	if (!v->e)
		error(10, v);
	v->f = mlx_xpm_file_to_image(v->mlx, "Images/0.xpm", &w, &h);
	if (!v->f)
		error(10, v);
	v->w = mlx_xpm_file_to_image(v->mlx, "Images/1.xpm", &w, &h);
	if (!v->w)
		error(10, v);
	v->p_e = mlx_xpm_file_to_image(v->mlx, "Images/rabit_exit.xpm", &w, &h);
	v->m = mlx_xpm_file_to_image(v->mlx, "Images/Enemy.xpm", &w, &h);
	if (!v->p_e || !v->m)
		error(10, v);
}

void	check_filetype(char *filename, t_vars *vars)
{
	char	*extension;

	extension = ft_strchr(filename, '/');
	if (ft_strlen(extension + 1) <= ft_strlen(".ber"))
		error(8, vars);
	if (ft_memcmp(extension + 1, "..ber", ft_strlen("..ber")) == 0)
		error(8, vars);
	extension = ft_strrchr(filename, '.');
	if (ft_memcmp(extension, ".ber", ft_strlen(".ber")) != 0)
		error(8, vars);
}
