

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "so_long.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**s;
	void	*back;
	void	*w;
	void	*w1;
	void	*p;
	void	*collect;
	void	*d;
	void	*e;
	void	*collect1;
	void	*de;
    int		steps;
	int		loop;

}				t_vars;

char	*get_next_line(int fd);
int		checkcollect(t_vars *var);
int     deal_key(int key, t_vars *var);
int		draw(t_vars	*var);
void	drawdead(t_vars	*var);
void	declaringimages(t_vars	*var);
void	forward(t_vars	*var);
void	backward(t_vars	*var);
void	upward(t_vars	*var);
void	downward(t_vars	*var);
int		close1(int key, t_vars	*var);
int		checkthewalls(t_vars	*var);

#endif