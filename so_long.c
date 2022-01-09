/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:42:16 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/24 20:42:18 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*c;
	int		i;

	i = 0;
	a = (char *)s1;
	b = (char *)s2;
	if (!(s1) && (s2))
		return (strdup(s2));
	c = (char *)malloc((strlen(a) + strlen(b) + 1) * 1);
	if (!c)
		return (NULL);
	strcpy(c, a);
	strcat(c, b);
	return (c);
}

char	*readline(char *s, char *buf, char *stati, int fd)
{
	int		i;
	void	*ptr;

	while (s == NULL || !strchr(s, '\n'))
	{
		i = read(fd, buf, 1000);
		if (i <= 0)
		{
			if (stati && *stati)
				free(stati);
			if (s && *s)
				return (free(buf), s);
			return (free(buf), free(s), NULL);
		}
		ptr = s;
		s = ft_strjoin(s, buf);
		free(ptr);
		bzero(buf, 1000 + 1);
	}
	return (free(buf), s);
}

/*******************/

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
	static char	*stati;

	s = NULL;
	if (stati != NULL)
	{
		s = strdup(stati);
		free(stati);
		stati = NULL;
	}
	buf = (char *)calloc(1000, sizeof(char));
	s = readline(s, buf, stati, fd);
	if (s == NULL)
		return (NULL);
	if (strchr(s, '\n'))
	{
		stati = strdup(strchr(s, '\n') + 1);
		bzero(strchr(s, '\n') + 1, strlen(strchr(s, '\n') + 1));
	}
	return (s);
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**s;
	void	*background;
	void	*wall;
	void	*player;
	void	*collect;
	void	*door;
}				t_vars;


void	draw(t_vars	*var)
{
	int	x;
	int y;
	int x1;
	int y1;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	while(var->s[x] != NULL)
		{
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == '1')
				{
					mlx_put_image_to_window(var->mlx, var->win, var->wall, x1, y1);
				}
				else if (var->s[x][y] == 'C')
				{
					mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
					mlx_put_image_to_window(var->mlx, var->win, var->collect, x1, y1);
				}
				else if (var->s[x][y] == 'P')
				{
					
					mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
					mlx_put_image_to_window(var->mlx, var->win, var->player, x1, y1);
				}
				else if (var->s[x][y] == '0')
				{
					mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
				}
				else if (var->s[x][y] == 'E')
				{
					mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
					mlx_put_image_to_window(var->mlx, var->win, var->door, x1, y1);
				}
				x1 += 50;
				y++;
			}
			x++;
			
			y1 += 50;
			x1 = 0;
		}
}

int	deal_key(int key, t_vars *var)
{
	int		x;
	int		x1;
	int 	y;
	int		y1;

	x = 0;
	y1 = 0;
	x1 = 0;
	y = 0;

	//printf("%s\n", var->s[x]);
	if (key == 2)
	{
		while (var->s[x + 1] != NULL)
		{
			y = 0;
			while(var->s[x][y] != '\n')
			{
				if (var->s[x][y] == 'P'  && var->s[x][y + 1] != '1')
				{	
					printf("P%c\n", var->s[x][y]);
					var->s[x][y] = '0';
					var->s[x][y + 1] = 'P';
					y += 2;
					break ;
				}
				else
				{
					y++;
				}
			}
			x++;
		}
	}
	if (key == 0)
	{
		while (var->s[x + 1] != 0)
		{ 
			y = 0;
			while(var->s[x][y] != '\n')
			{
				if (var->s[x][y] == 'P' && var->s[x][y - 1] != '1')
				{	
					printf("P%c\n", var->s[x][y]);
					var->s[x][y] = '0';
					var->s[x][y - 1] = 'P';
					y++;
					break ;
				}
				else
				{
					y++;
				}
			}
			x++;
		}
	}
	if (key == 13)
	{
		while (var->s[x + 1] != NULL)
		{
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == 'P' && var->s[x - 1][y] != '1')
				{	
					printf("P%c\n", var->s[x][y]);
					var->s[x][y] = '0';
					var->s[x - 1][y] = 'P';
					break ;
				}
				else
				{
					y++;
				}
			}
			x++;
		}
	}
	if (key == 1)
	{
		while (var->s[x] != NULL)
		{
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == 'P' && var->s[x + 1][y] != '1')
				{	
					printf("P%c\n", var->s[x][y]);
					var->s[x][y] = '0';
					var->s[x + 1][y] = 'P';
					x++;
					break ;
				}
				else
				{
					y++;
				}
			}
			x++;
		}
	}
		
	mlx_clear_window(var->mlx, var->win);
	draw(var);
	
	return 0;
}




int main(int argc, char *argv[])
{
	t_vars	var;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	//char	**s;
	char	*a;

	int		fd;
	int		width;
	int		height;
	int		i;
	int		x;
	int		y;
	int		o;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	fd = 0;
	i = 0;
	x = 0;
	y = 0;
	o = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	width = 2;
	height = 2;

	fd = open(argv[1], O_RDONLY);
	a = get_next_line(fd);
	y2 = strlen(a);
	while(a != NULL)
	{
		a = get_next_line(fd);
		x2++;
	}
	close(fd);
	y2 -= 1;
	var.s = (char**)calloc(x2, 1);
	x = 0;
	i = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	var.s[x] = get_next_line(fd);
	while (var.s[x])
	{
		x++;
		var.s[x] = get_next_line(fd);
		
	}
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "My First Game");


	var.wall = mlx_xpm_file_to_image(var.mlx, "./img/wall.xpm", &width, &height);
	var.collect = mlx_xpm_file_to_image(var.mlx, "./img/heart1.xpm", &width, &height);
	var.background = mlx_xpm_file_to_image(var.mlx, "./img/wall1.xpm", &width, &height);
	var.player = mlx_xpm_file_to_image(var.mlx, "./img/idle.xpm", &width, &height);
	var.door = mlx_xpm_file_to_image(var.mlx, "./img/door.xpm", &width, &height);
	x = 0;
	y = 0;
	draw(&var);
	
	mlx_key_hook(var.win, deal_key, &var);

	mlx_loop(var.mlx);
	return 0;
}

