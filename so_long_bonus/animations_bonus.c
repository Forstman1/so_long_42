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
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil1.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &x, &y);
	x = 0;
	if (var->loop == 12)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && var->s[x][y - 1] == '0')
				{
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
	draw(var);
}

void	secondturn(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	destroyimagesanimations(var);
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil3.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy3.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass2.xpm", &x, &y);
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
	var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil2.xpm", &x, &y);
	var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm", &x, &y);
	var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &x, &y);
	x = 0;
	if (var->loop == 32)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && var->s[x][y + 1] == '0')
				{
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
	else if (var->loop > 30 && var->loop < 50)
		thirdturn(var);
	else
	{
		var->loop = 0;
		draw(var);
	}
	return (0);
}
