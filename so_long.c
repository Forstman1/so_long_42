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

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*s;

	int		fd;
	int		width;
	int		height;
	int i;

	fd = 0;
	i = 0;
	width = 0;
	height = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "My First Game");
	fd = open(argv[1], O_RDONLY);
	while(s != NULL)
	{
		s = get_next_line(fd);
	}


	img = mlx_xpm_file_to_image(mlx, "./hello.xpm", &width, &height);

	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

	mlx_loop(mlx);
	return 0;
}
