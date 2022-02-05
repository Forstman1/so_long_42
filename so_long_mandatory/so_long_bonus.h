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

typedef struct s_vars_bonus {
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
}				t_vars_bonus;

char	*get_next_line(int fd);
int		checkcollectbonus(t_vars_bonus *var);
int		deal_key_bonus(int key, t_vars_bonus *var);
int		draw_bonus(t_vars_bonus	*var);
void	declaringimagesbonus(t_vars_bonus	*var);
void	forwardbonus(t_vars_bonus	*var);
void	backwardbonus(t_vars_bonus	*var);
void	upwardbonus(t_vars_bonus	*var);
void	downwardbonus(t_vars_bonus	*var);
int		close1bonus(int key, t_vars_bonus	*var);
int		checkthewallsbonus(t_vars_bonus	*var);
void	destroyimagesbonus(t_vars_bonus	*var);
int		animations(t_vars_bonus	*var);
void	destroyimagesanimations(t_vars_bonus *var);
void	puttingplayerbonus(t_vars_bonus	*var, int x1, int y1);
void	puttingrass_bonus(t_vars_bonus	*var, int x1, int y1);
void	puttingcollectible(t_vars_bonus	*var, int x1, int y1);
void	downward1(t_vars_bonus *var, int *x);
void	backward1(t_vars_bonus *var, int x);
void	forward1(t_vars_bonus *var, int x);
void	upward1(t_vars_bonus *var, int x);
void	checkcollectibles(t_vars_bonus *var, int *y);

#endif
