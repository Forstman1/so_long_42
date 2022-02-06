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

#include "so_long_bonus.h"
#include "mlx.h"

void	declaringimages(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	var->w = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &x, &y);
	var->col = mlx_xpm_file_to_image(var->mlx, "./img_bonus/coll.xpm", &x, &y);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil1.xpm", &x, &y);
	var->d = mlx_xpm_file_to_image(var->mlx, "./img_bonus/door1.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy1.xpm", &x, &y);
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
	write(1, "YOU WON\n", 8);
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
	mlx_clear_window(var->mlx, var->win);
	declaringimages(var);
	draw(var);
	return (0);
}
