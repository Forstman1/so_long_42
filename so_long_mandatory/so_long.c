/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:24:19 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/14 15:24:21 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include <time.h>

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*temp;
	int		i;

	i = 0;
	save[0] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\0')
			break;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	return (strdup(save));
}

int	draw(t_vars *var)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;

	while (var->s[x])
	{

		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == '1')
				mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
			else if (var->s[x][y] == 'C')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->collect1, x1, y1);
			}
			else if (var->s[x][y] == 'P')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->p, x1, y1);
			}
			else if (var->s[x][y] == '0')
				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
			else if (var->s[x][y] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->d, x1, y1);
			}
			x1 += 50;
			y++;
		}
		x++;
		y1 += 50;
		x1 = 0;
	}
	return (0);
}
int close1(int key, t_list	*var)
{
	exit(0);
	return 0;
}

int	main(int argc, char *argv[])
{
	t_vars	var;
	char	*a;
	int		fd;
	int		x2;
	int		y2;

	x2 = 0;
	y2 = 0;
	fd = open(argv[1], O_RDONLY);
	a = get_next_line(fd);
	var.s = ft_split(a, '\n');
	y2 = strlen(var.s[0]);
	while (var.s[x2])
		x2++;
	free(a);
	close(fd);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "Forstman Funds");
	if (checkthewalls(&var))
	{
		free(var.mlx);
		free(var.win);
		printf("ERROR\n");
		free(var.s);
		exit(0);
	}
	declaringimages(&var);
	draw(&var);
	mlx_key_hook(var.win, deal_key, &var);
	mlx_hook(var.win, 17, 0, close1, &var);
	//mlx_loop_hook(var.mlx, draw, &var);
	mlx_loop(var.mlx);
	return (0);
}
