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

/*******************/

char	*readline(char *s, char *buf, char *stati, int fd)
{
	int		i;
	void	*ptr;

	while (s == NULL || !strchr(s, '\n'))
	{
		i = read(fd, buf, 1);
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
		bzero(buf, 1 + 1);
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
	buf = (char *)calloc(1 + 1, sizeof(char));
	s = readline(s, buf, stati, fd);
	if (s == NULL)
		return (NULL);
	return (s);
}

int	deal_key1(int key, void *param)
{
	// char	**s;
	// int x;
	// int y;

	// x = 0;
	// y = 0;
	// s = (char**)param;

	if (key == 13)
	{
		printf("woriking");
	}
	if (key == 1)
	{
		printf("working");
	}
	//printf("%d", key);
	//printf("working");
	// if (key == 13)
	// {
	// 	while (s[x])
	// 	{
	// 		while(s[x][y])
	// 		{
	// 			if (s[x][y] == 'P')
	// 			{

	// 			}
	// 			y++;
	// 		}
	// 		x++;
	// 	}
	// 	printf("working\n");
	// }

	return (0);
}


int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	**s;
	char	*a;

	int		fd;
	int		width;
	int		height;
	int		i;
	int		x;
	int		y;
	int		o;
	int		hit;
	int		x1;
	int		y1;

	fd = 0;
	i = 0;
	x = 0;
	y = 0;
	o = 0;
	x1 = 0;
	y1 = 0;
	hit = 0;
	width = 2;
	height = 2;
	mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	a = get_next_line(fd);
	y = strlen(a);
	while(a != NULL)
	{
		a = get_next_line(fd);
		x++;
	}
	y -= 1;
	mlx_win = mlx_new_window(mlx, 50 * y, 50 * x, "My First Game");
	s = (char**)calloc(x, 1);
	close(fd);
	x = 0;
	i = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	s[x] = get_next_line(fd);

	while(s[x])
	{
		y = 0;
		while(s[x][y])
		{
			if (s[x][y] == '1')
			{
				img = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
			}
			else if (s[x][y] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
				img = mlx_xpm_file_to_image(mlx, "./img/heart1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
			}
			else if (s[x][y] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
				img = mlx_xpm_file_to_image(mlx, "./img/idle.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
			}
			else if (s[x][y] == '0')
			{
				img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
			}
			else if (s[x][y] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
				img = mlx_xpm_file_to_image(mlx, "./img/door.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, img, x1, y1);
			}
			x1 += 50;
			y++;
		}
		x++;
		s[x] = get_next_line(fd);
		printf("%s", s[x]);
		y1 += 50;
		x1 = 0;
	}

	mlx_key_hook(mlx_win, deal_key1, (void*)0);
	mlx_mouse_hook(mlx_win, deal_key1, (void *)0);
	mlx_loop(mlx);
	return 0;
}







	// while(s[i] != 0)
	// {
	// 	if (s[i] == '1')
	// 	{
	// 		img = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 	}
	// 	else if (s[i] == 'C')
	// 	{
	// 		img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 		img = mlx_xpm_file_to_image(mlx, "./img/heart1.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 	}
	// 	else if (s[i] == 'P')
	// 	{
	// 		img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 		img = mlx_xpm_file_to_image(mlx, "./img/idle.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 	}
	// 	else if (s[i] == '0')
	// 	{
	// 		img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 	}
	// 	else if (s[i] == 'E')
	// 	{
	// 		img = mlx_xpm_file_to_image(mlx, "./img/wall1.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 		img = mlx_xpm_file_to_image(mlx, "./img/door.xpm", &width, &height);
	// 		mlx_put_image_to_window(mlx, mlx_win, img, x, y);
	// 	}
	// 	x += 50;
	// 	i++;
	// 	if (s[i] == '\n')
	// 	{
	// 		free(s);
	// 		s = get_next_line(fd);
	// 		if (s == NULL)
	// 			return 0;
	// 		printf("%s", s);
	// 		y += 50;
	// 		x = 0;
	// 		i = 0;
	// 	}
	// }