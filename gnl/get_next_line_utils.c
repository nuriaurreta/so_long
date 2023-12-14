/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:23:30 by nuria             #+#    #+#             */
/*   Updated: 2023/11/30 17:31:34 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*scopy;

	if (!s1)
		return (0);
	scopy = malloc(ft_strlen(s1) + 1);
	if (scopy == NULL)
		return (NULL);
	ft_strlcpy (scopy, s1, ft_strlen(s1) + 1);
	return (scopy);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;

	i = 0;
	c1 = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i++;
	}
	if (!c1)
		return ((char *)(s + i));
	return (0);
}

void	ifminus(char *chars)
{
	if (chars)
	{
		free(chars);
		chars = 0;
	}
}