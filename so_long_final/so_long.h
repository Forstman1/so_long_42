/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 03:32:30 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 03:32:33 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "so_long.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**s;
	void	*back;
	void	*w;
	void	*p;
	void	*c;
	void	*d;
	int		steps;
}				t_vars;

char	*get_next_line(int fd);
int		checkcollect(t_vars *var);
int		deal_key(int key, t_vars *var);
int		draw(t_vars	*var);
void	drawdead(t_vars	*var);
void	declaringimages(t_vars	*var);
void	forward(t_vars	*var);
void	backward(t_vars	*var);
void	upward(t_vars	*var);
void	downward(t_vars	*var);
int		close1(int key);
int		checkthewalls(t_vars	*var, int x2);
void	destroyimages(t_vars	*var);
void	drawingfunc(t_vars	*var);
void	puttingimages(t_vars	*var, int x, int y, int y1);
void	puttingrass(t_vars	*var, int x1, int y1);
void	puttingplayer(t_vars	*var, int x1, int y1);
void	puttingcollectible(t_vars	*var, int x1, int y1);
int		checkvalid(char *a, t_vars	*var);
void	errors(void);
int		checkexit(t_vars	*var);
int		checkplayer(t_vars	*var);

#endif
