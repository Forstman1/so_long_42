/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttingimages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:52:19 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/15 21:52:22 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puttingcollectible(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->c, x1, y1);
}

void	puttingplayer(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->p, x1, y1);
}

void	puttingrass(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
}

void	puttingimages(t_vars	*var, int x, int y, int y1)
{
	int	x1;

	x1 = 0;
	while (var->s[x][y])
	{
		if (var->s[x][y] == '1')
			puttingrass(var, x1, y1);
		else if (var->s[x][y] == 'C')
			puttingcollectible(var, x1, y1);
		else if (var->s[x][y] == 'P')
			puttingplayer(var, x1, y1);
		else if (var->s[x][y] == '0')
			mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
		else if (var->s[x][y] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
			mlx_put_image_to_window(var->mlx, var->win, var->d, x1, y1);
		}
		else
			errors();
		x1 += 50;
		y++;
	}
}

int	draw(t_vars *var)
{
	int		x;
	int		y;
	int		y1;

	x = 0;
	y1 = 0;
	while (var->s[x])
	{
		y = 0;
		puttingimages(var, x, y, y1);
		y1 += 50;
		x++;
	}
	return (0);
}
