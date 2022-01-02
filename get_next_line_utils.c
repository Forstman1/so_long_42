/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:10 by sahafid           #+#    #+#             */
/*   Updated: 2021/12/02 18:30:12 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*******************/

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*dest;
	char	*a;

	src_len = ft_strlen(src);
	a = (char *)src;
	dest = (char *)malloc(src_len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, a);
	return (dest);
}

/*******************/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*******************/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[n] != '\0')
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}

/*******************/

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
		return (ft_strdup(s2));
	c = (char *)malloc((ft_strlen(a) + ft_strlen(b) + 1) * 1);
	if (!c)
		return (NULL);
	ft_strcpy(c, a);
	ft_strcat(c, b);
	return (c);
}
