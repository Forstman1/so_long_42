/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:16:54 by sahafid           #+#    #+#             */
/*   Updated: 2021/11/21 16:16:56 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = s;
	while (i < n)
		c[i++] = 0;
	s = c;
}

/*******************/

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	b;

	i = 0;
	ptr = (char *)malloc(n * size);
	if (!ptr)
		return (0);
	b = n * size;
	while (i < b)
		ptr[i++] = 0;
	return (ptr);
}

/*******************/

char	*ft_strchr(const char *str, int c)
{
	char	*h;
	char	a;
	int		i;

	h = (char *)str;
	i = 0;
	a = (char)c;
	while (h[i] != '\0')
	{
		if (a == h[i])
			return (&h[i]);
		i++;
	}
	if (a == '\0')
		return (&h[i]);
	return (0);
}

/*******************/

char	*readline(char *s, char *buf, char *stati, int fd)
{
	int		i;
	void	*ptr;

	while (s == NULL || !ft_strchr(s, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
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
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	return (free(buf), s);
}

/*******************/

char	*get_next_line(int fd)
{
	char		*s;
	char		*buf;
	static char	*stati;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	s = NULL;
	if (stati != NULL)
	{
		s = ft_strdup(stati);
		free(stati);
		stati = NULL;
	}
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	s = readline(s, buf, stati, fd);
	if (s == NULL)
		return (NULL);
	if (ft_strchr(s, '\n'))
	{
		stati = ft_strdup(ft_strchr(s, '\n') + 1);
		ft_bzero(ft_strchr(s, '\n') + 1, ft_strlen(ft_strchr(s, '\n') + 1));
	}
	return (s);
}
