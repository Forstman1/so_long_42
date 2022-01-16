/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:40 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:24:43 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	destroyimages(t_vars	*var)
{
	mlx_destroy_image(var->mlx, var->w);
	mlx_destroy_image(var->mlx, var->c);
	mlx_destroy_image(var->mlx, var->back);
	mlx_destroy_image(var->mlx, var->p);
	mlx_destroy_image(var->mlx, var->d);
	mlx_destroy_image(var->mlx, var->e);
}

void	declaringimages(t_vars	*var)
{
	int	hei;
	int	wid;

	hei = 0;
	wid = 0;
	var->w = mlx_xpm_file_to_image(var->mlx, "./img/grass.xpm", &wid, &hei);
	var->c = mlx_xpm_file_to_image(var->mlx, "./img/key3.xpm", &wid, &hei);
	var->back = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &wid, &hei);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil3.xpm", &wid, &hei);
	var->d = mlx_xpm_file_to_image(var->mlx, "./img/door1.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy3.xpm", &wid, &hei);
}

int	checkcollect(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var->s[x])
	{
		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	deal_key(int key, t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 2)
		forward(var);
	if (key == 0)
		backward(var);
	if (key == 13)
		upward(var);
	if (key == 1)
		downward(var);
	if (key == 53)
		exit(0);
	printf("steps : %d\n", var->steps);
	mlx_clear_window(var->mlx, var->win);
	destroyimages(var);
	declaringimages(var);
	draw(var);
	return (0);
}
