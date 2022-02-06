/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movingfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:54 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:25:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	checkcollectibles(t_vars *var, int *y)
{
	if (checkcollect(var))
	{
		mlx_destroy_window(var->mlx, var->win);
		free(var->s);
		exit(0);
	}
	else if (!checkcollect(var))
		(*y)++;
}

void	forward(t_vars *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		forward1(var, x);
		x++;
	}
}

void	backward(t_vars *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		backward1(var, x);
		x++;
	}
}

void	upward(t_vars *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		upward1(var, &x);
		x++;
	}
}

void	downward(t_vars *var)
{
	int	x;

	x = 0;
	while (var->s[x] != NULL)
	{
		downward1(var, &x);
		x++;
	}
}
