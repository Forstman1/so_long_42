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

void	declaringimagesbonus(t_vars_bonus *var)
{
	int	hei;
	int	wid;

	hei = 0;
	wid = 0;
	var->w = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &wid, &hei);
	var->col = mlx_xpm_file_to_image(var->mlx, "./img_bonus/key3.xpm", &wid, &hei);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil1.xpm", &wid, &hei);
	var->d = mlx_xpm_file_to_image(var->mlx, "./img_bonus/door1.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy1.xpm", &wid, &hei);
}

int	checkcollectbonus(t_vars_bonus *var)
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

int	deal_key_bonus(int key, t_vars_bonus *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 2)
		forwardbonus(var);
	if (key == 0)
		backwardbonus(var);
	if (key == 13)
		upwardbonus(var);
	if (key == 1)
		downwardbonus(var);
	if (key == 53)
		exit(0);
	mlx_clear_window(var->mlx, var->win);
	declaringimagesbonus(var);
	draw_bonus(var);
	return (0);
}
