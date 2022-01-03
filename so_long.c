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

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*s;

	int		fd;
	int		width;
	int		height;
	int		i;
	int		x;
	int		y;
	int		o;

	fd = 0;
	i = 0;
	x = 0;
	y = 0;
	o = 0;
	width = 2;
	height = 2;
	mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	s = get_next_line(fd);
	i = strlen(s);
	i -= 1;
	while(1)
	{
		s = get_next_line(fd);
		o++;
		if (s == NULL)
			break ;
	}
	mlx_win = mlx_new_window(mlx, 50 * i, 50 * o, "My First Game");
	img = mlx_xpm_file_to_image(mlx, "./hello.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	i = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	s = get_next_line(fd);
	while(s[i] != 0)
	{
		if (s[i] == '1')
		{
			img = mlx_xpm_file_to_image(mlx, "./test.xpm", &width, &height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
		}
		else if (s[i] == 'C')
		{
			img = mlx_xpm_file_to_image(mlx, "./heart1.xpm", &width, &height);
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
		}
		x += 50;
		i++;
		if (s[i] == '\n')
		{
			free(s);
			s = get_next_line(fd);
			if (s == NULL)
				return 0;
			printf("%s", s);
			y += 50;
			x = 0;
			i = 0;
		}
	}

	mlx_loop(mlx);
	return 0;
}
