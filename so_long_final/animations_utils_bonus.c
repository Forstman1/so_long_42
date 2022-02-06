/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:37:12 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 16:38:16 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroyimagesbonus(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->w);
	mlx_destroy_image(var->mlx, var->w1);
	mlx_destroy_image(var->mlx, var->col);
	mlx_destroy_image(var->mlx, var->p);
	mlx_destroy_image(var->mlx, var->d);
	mlx_destroy_image(var->mlx, var->e);
}

void	destroyimagesanimations(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->p);
	mlx_destroy_image(var->mlx, var->e);
	mlx_destroy_image(var->mlx, var->w1);
}

void	enemymoving1(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (var->loop == 12)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && \
				(var->s[x][y - 1] == '0' || var->s[x][y - 1] == 'P'))
				{
					if (var->s[x][y - 1] == 'P')
						losing();
					var->s[x][y] = '0';
					var->s[x][y - 1] = 'I';
				}
				y++;
			}
			x++;
		}
	}
}

void	enemymoving2(t_vars	*var)
{
	int	x;
	int	y;

	x = 0;
	if (var->loop == 32)
	{
		while (var->s[x])
		{
			y = 0;
			while (var->s[x][y])
			{
				if (var->s[x][y] == 'I' && \
				(var->s[x][y + 1] == '0' || var->s[x][y + 1] == 'P'))
				{
					if (var->s[x][y + 1] == 'P')
						losing();
					var->s[x][y] = '0';
					var->s[x][y + 1] = 'I';
					y++;
				}
				y++;
			}
			x++;
		}
	}
}
