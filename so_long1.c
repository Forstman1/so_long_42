

#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

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

// char	*readline(char *s, char *buf, int fd)
// {
// 	int		i;
// 	void	*ptr;

// 	while (s == NULL || !strchr(s, '\n'))
// 	{
// 		i = read(fd, buf, 1);
// 		if (i <= 0)
// 		{
// 			if (s && *s)
// 				return (s);
// 			return (NULL);
// 		}
// 		ptr = s;
// 		s = ft_strjoin(s, buf);
// 		free(ptr);
// 		bzero(buf, 1 + 1);
// 	}
// 	return (s);
// }

/*******************/

char	*get_next_line(int fd)
{
	char save[999999];
    char buff[1];
    char *temp;
    int i;

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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    char    *buff;
	char	**s;
	void	*background;
	void	*wall;
	void	*player;
	void	*collect;
	void	*door;
	void	*collect1;
    int     steps;
	int		loop;
}				t_vars;

int		checkcollect(t_vars *var)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (var->s[x])
	{
		y = 0;
		while (var->s[x][y])
		{
			if (var->s[x][y] == 'C')
				return 0;
			y++;
		}
		x++;
	}
	return 1;
}

int	draw(t_vars	*var)
{
	int	x;
	int y;
	int x1;
	int y1;
	int loop;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	loop = 0;
    if (var->loop == 10000)
		var->loop = 2;
	while(var->s[x])
	{
        
		y = 0;
		while(var->s[x][y])
		{
			//printf("ana hna\n");
			if (var->s[x][y] == '1')
				mlx_put_image_to_window(var->mlx, var->win, var->wall, x1, y1);
			else if (var->s[x][y] == 'C')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
				if ((var->loop % 2) == 0)
				{
					mlx_put_image_to_window(var->mlx, var->win, var->collect, x1, y1);
					var->loop++;
				}
				else
				{			
					//mlx_put_image_to_window(var->mlx, var->win, var->collect1, x1, y1);
					var->loop++;
				}
			}
			else if (var->s[x][y] == 'P')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
				mlx_put_image_to_window(var->mlx, var->win, var->player, x1, y1);
			}
			else if (var->s[x][y] == '0')
				mlx_put_image_to_window(var->mlx, var->win, var->background, x1, y1);
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
	return 0;
}

int	deal_key(int key, t_vars *var)
{
	int		x;
	int 	y;

	x = 0;
	y = 0;

	if (key == 2)
	{
		while (var->s[x])
		{
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == 'P'  && var->s[x][y + 1] != '1' && var->s[x][y + 1] != 'E')
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
						//free(var->s);
						return 0;
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
	if (key == 0)
	{
		while (var->s[x])
		{ 
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == 'P' && var->s[x][y - 1] != '1'&& var->s[x][y - 1] != 'E')
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
						//free(var->s);
						return 0;
					}
					else if (!checkcollect(var))
					{
						y++;
					}
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
		while (var->s[x])
		{
			y = 0;
			while(var->s[x][y])
			{
				if (var->s[x][y] == 'P' && var->s[x - 1][y] != '1' && var->s[x - 1][y] != 'E')
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
						return 0;
					}
					else if (!checkcollect(var))
					{
						y++;
					}
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
				if (var->s[x][y] == 'P' && var->s[x + 1][y] != '1' && var->s[x + 1][y] != 'E')
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
						//free(var->s);
						return 0;
					}
					else if (!checkcollect(var))
					{
						y++;
					}
				}
				else
				{
					y++;
				}
			}
			x++;
		}
	}
	printf("Steps :%d\n", var->steps);
	mlx_clear_window(var->mlx, var->win);
	draw(var);
	
	return 0;
}



int main(int argc, char *argv[])
{


	t_vars	var;
    char    *a;
	int		fd;
	int		x;
	int		y;
	int		x2 = 0;
	int		y2 = 0;
	int		width;
	int		height;
	
    fd = open("fd.ber", O_RDONLY);
    var.buff = get_next_line(fd);
    var.s = ft_split(var.buff, '\n');
    y2 = strlen(var.s[0]);
    while (var.s[x2])
        x2++;
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 50 * y2, 50 * x2, "so long");

	var.wall = mlx_xpm_file_to_image(var.mlx, "./img/wall.xpm", &width, &height);
	var.collect = mlx_xpm_file_to_image(var.mlx, "./img/heart.xpm", &width, &height);
	var.collect1 = mlx_xpm_file_to_image(var.mlx, "./img/heart2.xpm", &width, &height);
	var.background = mlx_xpm_file_to_image(var.mlx, "./img/wall1.xpm", &width, &height);
	var.player = mlx_xpm_file_to_image(var.mlx, "./img/idle.xpm", &width, &height);
	var.door = mlx_xpm_file_to_image(var.mlx, "./img/door.xpm", &width, &height);
    //draw(&var);
	var.loop = 0;
	mlx_loop_hook(var.mlx, draw, &var);

	mlx_key_hook(var.win, deal_key, &var);

	mlx_loop(var.mlx);

	return 0;
}

