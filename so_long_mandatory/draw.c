/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:03:55 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 16:03:57 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puttingenemy(t_vars_bonus	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->e, x1, y1);
}

void	puttingimagesbonus(t_vars_bonus	*var, int x, int y, int y1)
{
	int	x1;

	x1 = 0;
	while (var->s[x][y])
	{
		if (var->s[x][y] == '1')
			puttingrass_bonus(var, x1, y1);
		else if (var->s[x][y] == 'C')
			puttingcollectible(var, x1, y1);
		else if (var->s[x][y] == 'P')
			puttingplayerbonus(var, x1, y1);
		else if (var->s[x][y] == '0')
			mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
		else if (var->s[x][y] == 'I')
			puttingenemy(var, x1, y1);
		else if (var->s[x][y] == 'E')
		{
			mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
			mlx_put_image_to_window(var->mlx, var->win, var->d, x1, y1);
		}
		x1 += 50;
		y++;
	}
}

int	draw_bonus(t_vars_bonus *var)
{
	int		x;
	char	*a;
	char	*b;
	int		y;
	int		y1;

	x = 0;
	y1 = 0;
	while (var->s[x])
	{
		y = 0;
		puttingimagesbonus(var, x, y, y1);
		y1 += 50;
		x++;
	}
	b = ft_itoa(var->steps);
	a = ft_strjoin("Move : ", b);
	mlx_string_put(var->mlx, var->win, 0, 10, 0x0000FF00, a);
	free(a);
	free(b);
	return (0);
}
