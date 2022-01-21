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

void	destroyimages(t_vars *var)
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
