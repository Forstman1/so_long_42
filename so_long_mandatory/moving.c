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

void	checkcollectibles(t_vars_bonus *var, int *y)
{
	if (checkcollectbonus(var))
	{
		mlx_destroy_window(var->mlx, var->win);
		free(var->s);
		exit(0);
	}
	else if (!checkcollectbonus(var))
		(*y)++;
}

void	forwardbonus(t_vars_bonus *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		forward1(var, x);
		x++;
	}
}

void	backwardbonus(t_vars_bonus *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		backward1(var, x);
		x++;
	}
}

void	upwardbonus(t_vars_bonus *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		upward1(var, x);
		x++;
	}
}

void	downwardbonus(t_vars_bonus *var)
{
	int	x;

	x = 0;
	while (var->s[x])
	{
		downward1(var, &x);
		x++;
	}
}
