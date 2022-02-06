/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:25 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/21 15:59:27 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkplayer(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var->s[x])
	{
		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == 'P')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	errors(void)
{
	write(1, "ERROR\n", 6);
	write(1, "Misconfiguration In The Map\n", 27);
	exit(0);
}

int	checkexit(t_vars *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var->s[x])
	{
		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	checkvalid(char *a, t_vars	*var)
{
	int	i;

	i = 0;
	if (checkplayer(var))
		errors();
	if (checkcollect(var))
		errors();
	if (checkexit(var))
		errors();
	while (a[i])
	{
		if (a[i] == '.')
		{
			if (a[i + 1] == 'b' && a[i + 2] == 'e' && \
				a[i + 3] == 'r' && a[i + 4] == '\0')
				return (0);
			else
				errors();
		}
		i++;
	}
	errors();
	return (1);
}
