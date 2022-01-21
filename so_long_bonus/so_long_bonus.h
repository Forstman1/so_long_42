/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:59:39 by sahafid           #+#    #+#             */
/*   Updated: 2022/01/16 19:59:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "so_long_bonus.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**s;
	void	*back;
	void	*w;
	void	*w1;
	void	*p;
	void	*col;
	void	*d;
	void	*e;
	int		steps;
	int		loop;
}				t_vars;

char	*get_next_line(int fd);
int		checkcollect(t_vars *var);
int		deal_key(int key, t_vars *var);
int		draw(t_vars	*var);
void	declaringimages(t_vars	*var);
void	forward(t_vars	*var);
void	backward(t_vars	*var);
void	upward(t_vars	*var);
void	downward(t_vars	*var);
int		close1(int key);
int		checkthewalls(t_vars	*var);
void	destroyimages(t_vars	*var);
void	checkcollectibles(t_vars *var, int *y);
int		animations(t_vars	*var);
void	destroyimagesanimations(t_vars *var);
void	puttingplayer(t_vars	*var, int x1, int y1);
void	puttingrass(t_vars	*var, int x1, int y1);
void	puttingcollectible(t_vars	*var, int x1, int y1);
void	backward1(t_vars *var, int x);
void	forward1(t_vars *var, int x);
void	downward1(t_vars *var, int *x);
void	upward1(t_vars *var, int *x);
int		checkexit(t_vars *var);
void	errors(void);
int		checkplayer(t_vars *var);
void	losing(void);
int		checkvalid(char *a, t_vars	*var);


#endif
