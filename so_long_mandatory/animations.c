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

void	firsturn(t_vars_bonus	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil1.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy1.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &x, &y);
	x = 0;
	if (var->loop == 12)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && (var->s[x][y - 1] == '0' || var->s[x][y - 1] == 'P'))
				{
					if (var->s[x][y - 1] == 'P')
						close1bonus(0, var);
					var->s[x][y] = '0';
					var->s[x][y - 1] = 'I';
					y += 1;
				}
				else
					y++;
			}
			x++;
		}
	}
	var->loop++;
	draw_bonus(var);
}

void	secondturn(t_vars_bonus	*var)
{
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil3.xpm", &wid, &hei);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy3.xpm", &wid, &hei);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass2.xpm", &wid, &hei);
	var->loop++;
	draw_bonus(var);
}

void	thirdturn(t_vars_bonus	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img_bonus/pixil2.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img_bonus/enemy2.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img_bonus/grass1.xpm", &x, &y);
	x = 0;
	if (var->loop == 32)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && (var->s[x][y + 1] == '0' || var->s[x][y + 1] == 'P'))
				{
					if (var->s[x][y + 1] == 'P')
						close1bonus(0, var);
					var->s[x][y] = '0';
					var->s[x][y + 1] = 'I';
					y += 2;
				}
				else
					y++;
			}
			x++;
		}
	}
	var->loop++;
	draw_bonus(var);
}

int	animations(t_vars_bonus *var)
{
	destroyimagesbonus(var);
	mlx_clear_window(var->mlx, var->win);
	declaringimagesbonus(var);
	if (var->loop <= 15)
		firsturn(var);
	else if (var->loop > 15 && var->loop <= 30)
		secondturn(var);
	else if (var->loop > 30 && var->loop < 45)
		thirdturn(var);
	else
	{
		var->loop = 0;
		draw_bonus(var);
	}
	return (0);
}
