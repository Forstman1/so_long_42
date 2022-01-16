/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:14:15 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 17:14:16 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puttingplayer(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->p, x1, y1);
}

void	puttingrass(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->w1, x1, y1);
}

void	puttingcollectible(t_vars	*var, int x1, int y1)
{
	mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
	mlx_put_image_to_window(var->mlx, var->win, var->col, x1, y1);
}
