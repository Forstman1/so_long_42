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
	char	*a;
	char	*b;
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
			{
				mlx_put_image_to_window(var->mlx, var->win, var->w, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->w1, x1, y1);
			}
			else if (var->s[x][y] == 'C')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->collect, x1, y1);
			}
			else if (var->s[x][y] == 'I')
			{

				mlx_put_image_to_window(var->mlx, var->win, var->back, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->e, x1, y1);
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
	b = ft_itoa(var->steps);
	a = ft_strjoin("Move : ", b);
	mlx_string_put(var->mlx, var->win, 0, 10, 0x0000FF00, a);
	free(a);
	free(b);
	return (0);
}

void	destroyimages(t_vars	*var)
{
	mlx_destroy_image(var->mlx, var->w);
	mlx_destroy_image(var->mlx, var->w1);
	mlx_destroy_image(var->mlx, var->collect);
	mlx_destroy_image(var->mlx, var->back);
	mlx_destroy_image(var->mlx, var->p);
	mlx_destroy_image(var->mlx, var->d);
	mlx_destroy_image(var->mlx, var->e);
}

int	animations(t_vars	*var)
{
	int width;
	int height;

	width = 0;
	height = 0;

	destroyimages(var);
	mlx_clear_window(var->mlx, var->win);
	declaringimages(var);
	if (var->loop <= 20)
	{
		mlx_destroy_image(var->mlx, var->p);
		mlx_destroy_image(var->mlx, var->e);
		mlx_destroy_image(var->mlx, var->w1);
		var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil1.xpm", &width, &height);
		var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm", &width, &height);
		var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &width, &height);
		var->loop++;
		draw(var);
	}
	else if (var->loop > 20 && var->loop <= 40)
	{
		mlx_destroy_image(var->mlx, var->p);
		mlx_destroy_image(var->mlx, var->e);
		mlx_destroy_image(var->mlx, var->w1);
		var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil3.xpm", &width, &height);
		var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy3.xpm", &width, &height);
		var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass2.xpm", &width, &height);
		var->loop++;
		draw(var);
	}
	else if (var->loop > 40 && var->loop < 60)
	{
		mlx_destroy_image(var->mlx, var->p);
		mlx_destroy_image(var->mlx, var->e);
		mlx_destroy_image(var->mlx, var->w1);
		var->p = mlx_xpm_file_to_image(var->mlx, "./img/pixil2.xpm", &width, &height);
		var->e = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm", &width, &height);
		var->w1 = mlx_xpm_file_to_image(var->mlx, "./img/grass1.xpm", &width, &height);
		var->loop++;
		draw(var);
	}
	else
	{
		var->loop = 0;
		draw(var);
	}
	return 0;
}


int close1(int key, t_vars	*var)
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
	var.loop = 0;
	fd = open(argv[1], O_RDONLY);
	a = get_next_line(fd);
	var.s = ft_split(a, '\n');
	y2 = ft_strlen(var.s[0]);
	while (var.s[x2])
		x2++;
	free(a);
	close(fd);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "Forstman Funds");
	if (checkthewalls(&var))
	{
		printf("ERROR\n");
		exit(0);
	}
	declaringimages(&var);
	mlx_loop_hook(var.mlx, animations, &var);

	mlx_key_hook(var.win, deal_key, &var);
	mlx_hook(var.win, 17, 0, close1, &var);
	
	mlx_loop(var.mlx);
	return (0);
}
