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
	mlx_destroy_image(var->mlx, var->collect);
	mlx_destroy_image(var->mlx, var->collect1);
	mlx_destroy_image(var->mlx, var->back);
	mlx_destroy_image(var->mlx, var->p);
	mlx_destroy_image(var->mlx, var->d);
	mlx_destroy_image(var->mlx, var->e);
	mlx_destroy_image(var->mlx, var->de);
}

void	declaringimages(t_vars	*var)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	var->w = mlx_xpm_file_to_image(var->mlx, "./img/wall3.xpm", &width, &height);
	var->collect = mlx_xpm_file_to_image(var->mlx, "./img/coin2.xpm", &width, &height);
	var->collect1 = mlx_xpm_file_to_image(var->mlx, "./img/coin2.xpm", &width, &height);
	var->back = mlx_xpm_file_to_image(var->mlx, "./img/wall1.xpm", &width, &height);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixel.xpm", &width, &height);
	var->d = mlx_xpm_file_to_image(var->mlx, "./img/door.xpm", &width, &height);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy.xpm", &width, &height);
	var->de = mlx_xpm_file_to_image(var->mlx, "./img/dead.xpm", &width, &height);
}

int	checkcollect(t_vars *var)
{
	int x;
	int y;

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
	int x;
	int y;

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
