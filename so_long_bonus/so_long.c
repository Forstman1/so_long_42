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
	int		i;

	i = 0;
	save[0] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\0')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	return (strdup(save));
}

int	close1(int key, t_vars	*var)
{
	exit(0);
	return (0);
}

void	drawingfunc(t_vars	*var)
{
	declaringimages(var);
	mlx_loop_hook(var->mlx, animations, var);
	mlx_key_hook(var->win, deal_key, var);
	mlx_hook(var->win, 17, 0, close1, var);
}

void	spliting(t_vars	*var, int fd, int *y2, int *x2)
{
	char	*a;

	a = get_next_line(fd);
	var->s = ft_split(a, '\n');
	(*y2) = ft_strlen(var->s[0]);
	while (var->s[(*x2)])
		(*x2)++;
	free(a);
}

int	main(int argc, char *argv[])
{
	t_vars	var;
	int		fd;
	int		x2;
	int		y2;

	x2 = 0;
	y2 = 0;
	var.loop = 0;
	fd = open(argv[1], O_RDONLY);
	spliting(&var, fd, &y2, &x2);
	close(fd);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "Forstman Funds");
	if (checkthewalls(&var))
	{
		printf("ERROR\n");
		exit(0);
	}
	drawingfunc(&var);
	mlx_loop(var.mlx);
	return (0);
}
