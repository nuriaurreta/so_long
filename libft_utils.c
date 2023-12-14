/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:29:27 by nuria             #+#    #+#             */
/*   Updated: 2023/12/13 15:44:22 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_strchr(const char *s, int c)
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

char	*sl_strdup(const char *s1)
{
	char	*scopia;

	scopia = malloc(sl_strlen(s1) + 1);
	if (scopia == NULL)
		return (NULL);
	sl_strlcpy (scopia, s1, sl_strlen(s1) + 1);
	return (scopia);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	dstsize;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	dstsize = sl_strlen(s1) + sl_strlen(s2) + 1;
	newstr = malloc(dstsize);
	if (!newstr)
		return (NULL);
	i = 0;
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

char	*sl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	lens;

	lens = sl_strlen(s);
	if (len > lens)
		len = lens;
	if (start + len > lens)
		len = lens - start;
	if (start > lens)
		return (sl_strdup (""));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	sl_strlcpy (substr, &s[start], len + 1);
	return (substr);
}

size_t	sl_strlcpy(char *dst, const char *src, size_t dstsize)
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
