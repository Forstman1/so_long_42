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

#include "so_long.h"

void	forward(t_vars	*var)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (var->s[x])
		{
			y = 0;
			while(var->s[x][y])
			{
                if (var->s[x][y] == 'P' && var->s[x][y + 1] == 'I')
                {
                    mlx_destroy_window(var->mlx, var->win);
					exit(0);
                }
				else if (var->s[x][y] == 'P'  && var->s[x][y + 1] != '1' && var->s[x][y + 1] != 'E')
				{	
					var->s[x][y] = '0';
					var->s[x][y + 1] = 'P';
					var->steps++;
					y += 2;
					break ;
				}
				else if (var->s[x][y] == 'P'  && var->s[x][y + 1] == 'E')
				{
					if (checkcollect(var))
					{
						mlx_destroy_window(var->mlx, var->win);
						free(var->s);
						exit(0);
					}
					else if (!checkcollect(var))
						y++;
				}
				else
					y++;
			}
			x++;
		}
}
void	backward(t_vars	*var)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (var->s[x])
		{ 
			y = 0;
			while(var->s[x][y])
			{
                if (var->s[x][y] == 'P' && var->s[x][y - 1] == 'I')
                {
                    mlx_destroy_window(var->mlx, var->win);
					exit(0);
                }
				else if (var->s[x][y] == 'P' && var->s[x][y - 1] != '1'&& var->s[x][y - 1] != 'E')
				{	
					var->s[x][y] = '0';
					var->s[x][y - 1] = 'P';
					var->steps++;
					break ;
				}
				else if (var->s[x][y] == 'P'  && var->s[x][y - 1] == 'E')
				{
					if (checkcollect(var))
					{
						mlx_destroy_window(var->mlx, var->win);
						free(var->s);
						exit(0);
					}
					else if (!checkcollect(var))
						y++;
				}
				else
					y++;
			}
			x++;
		}
}
void	upward(t_vars	*var)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (var->s[x])
		{
			y = 0;
			while(var->s[x][y])
			{
                if (var->s[x][y] == 'P' && var->s[x - 1][y] == 'I')
                {
                    mlx_destroy_window(var->mlx, var->win);
					exit(0);
                }
				else if (var->s[x][y] == 'P' && var->s[x - 1][y] != '1' && var->s[x - 1][y] != 'E')
				{	
					var->s[x][y] = '0';
					var->s[x - 1][y] = 'P';
					var->steps++;
					break ;
				}
				else if (var->s[x][y] == 'P'  && var->s[x - 1][y] == 'E')
				{
					if (checkcollect(var))
					{
						mlx_destroy_window(var->mlx, var->win);
						free(var->s);
						exit(0);
					}
					else if (!checkcollect(var))
						y++;
				}
				else
					y++;
			}
			x++;
		}
}

void	downward(t_vars	*var)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (var->s[x] != NULL)
		{
			y = 0;
			while(var->s[x][y])
			{
                if (var->s[x][y] == 'P' && var->s[x + 1][y] == 'I')
                {
                    mlx_destroy_window(var->mlx, var->win);
					exit(0);
                }
				else if (var->s[x][y] == 'P' && var->s[x + 1][y] != '1' && var->s[x + 1][y] != 'E')
				{	
					var->s[x][y] = '0';
					var->s[x + 1][y] = 'P';
					var->steps++;
					x++;
					break ;
				}
				else if (var->s[x][y] == 'P'  && var->s[x + 1][y] == 'E')
				{
					if (checkcollect(var))
					{
						mlx_destroy_window(var->mlx, var->win);
						free(var->s);
						exit(0);
					}
					else if (!checkcollect(var))
						y++;
				}
				else
					y++;
			}
			x++;
		}
}
