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

#include "so_long.h"

void	firsturn(t_vars	*var)
{
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil1.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &wid, &hei);
	var->loop++;
	draw(var);
}

void	secondturn(t_vars	*var)
{
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil3.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy3.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass2.xpm", &wid, &hei);
	var->loop++;
	draw(var);
}

void	thirdturn(t_vars	*var)
{
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil2.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &wid, &hei);
	var->loop++;
	draw(var);
}

int	animations(t_vars *var)
{
	destroyimages(var);
	mlx_clear_window(var->mlx, var->win);
	declaringimages(var);
	if (var->loop <= 15)
		firsturn(var);
	else if (var->loop > 15 && var->loop <= 30)
		secondturn(var);
	else if (var->loop > 30 && var->loop < 45)
		thirdturn(var);
	else
	{
		var->loop = 0;
		draw(var);
	}
	return (0);
}
