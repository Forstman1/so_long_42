/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:30:08 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 17:30:09 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	forward1(t_vars_bonus *var, int x)
{
	int	y;

	y = 0;
	while (var->s[x][y])
	{
		if (var->s[x][y] == 'P' && var->s[x][y + 1] == 'I')
			exit(0);
		else if (var->s[x][y] == 'P' && var->s[x][y + 1] != '1' &&
			var->s[x][y + 1] != 'E')
		{
			var->s[x][y] = '0';
			var->s[x][y + 1] = 'P';
			var->steps++;
			break ;
		}
		else if (var->s[x][y] == 'P' && var->s[x][y + 1] == 'E')
			checkcollectibles(var, &y);
		else
			y++;
	}
}

void	backward1(t_vars_bonus *var, int x)
{
	int	y;

	y = 0;
	while (var->s[x][y])
	{
		if (var->s[x][y] == 'P' && var->s[x][y - 1] == 'I')
			exit(0);
		else if (var->s[x][y] == 'P' && var->s[x][y - 1] != '1' &&
			var->s[x][y - 1] != 'E')
		{
			var->s[x][y] = '0';
			var->s[x][y - 1] = 'P';
			var->steps++;
			break ;
		}
		else if (var->s[x][y] == 'P' && var->s[x][y - 1] == 'E')
			checkcollectibles(var, &y);
		else
			y++;
	}
}

void	upward1(t_vars_bonus *var, int x)
{
	int	y;

	y = 0;
	while (var->s[x][y])
	{
		if (var->s[x][y] == 'P' && var->s[x - 1][y] == 'I')
			exit(0);
		else if (var->s[x][y] == 'P' && var->s[x - 1][y] != '1' &&
			var->s[x - 1][y] != 'E')
		{
			var->s[x][y] = '0';
			var->s[x - 1][y] = 'P';
			var->steps++;
			break ;
		}
		else if (var->s[x][y] == 'P' && var->s[x - 1][y] == 'E')
			checkcollectibles(var, &y);
		else
			y++;
	}
}

void	downward1(t_vars_bonus *var, int *x)
{
	int	y;

	y = 0;
	while (var->s[*x][y])
	{
		if (var->s[*x][y] == 'P' && var->s[*x + 1][y] == 'I')
			exit(0);
		else if (var->s[*x][y] == 'P' && var->s[*x + 1][y] != '1' &&
			var->s[*x + 1][y] != 'E')
		{
			var->s[*x][y] = '0';
			var->s[*x + 1][y] = 'P';
			var->steps++;
			*x += 2;
			break ;
		}
		else if (var->s[*x][y] == 'P' && var->s[*x + 1][y] == 'E')
			checkcollectibles(var, &y);
		else
			y++;
	}
}
