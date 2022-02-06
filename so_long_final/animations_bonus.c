/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:05:36 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 16:05:37 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	firsturn(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil1.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy1.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &x, &y);
	enemymoving1(var);
	var->loop++;
	draw(var);
}

void	secondturn(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil3.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy3.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass2.xpm", &x, &y);
	var->loop++;
	draw(var);
}

void	thirdturn(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil2.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy2.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &x, &y);
	enemymoving2(var);
	var->loop++;
	draw(var);
}

int	animations(t_vars *var)
{
	destroyimagesbonus(var);
	mlx_clear_window(var->mlx, var->win);
	declaringimages(var);
	if (var->loop <= 15)
		firsturn(var);
	else if (var->loop > 15 && var->loop <= 30)
		secondturn(var);
	else if (var->loop > 30 && var->loop < 50)
		thirdturn(var);
	else
	{
		var->loop = 0;
		draw(var);
	}
	return (0);
}
