/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:44:09 by nuria             #+#    #+#             */
/*   Updated: 2023/11/30 17:31:52 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*fill_line(int fd, char *chars, char *buffer);
char		*read_line(char *line);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	static char	*chars;
	char		*line;
	static char	buffer [BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line(fd, chars, buffer);
	if (!line)
		return (chars = 0, NULL);
	chars = read_line(line);
	return (line);
}

char	*fill_line(int fd, char *chars, char *buffer)
{
	ssize_t	bytes_read;
	char	*aux;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ifminus((char *)chars), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!chars)
			chars = ft_strdup("");
		aux = chars;
		chars = ft_strjoin(aux, buffer);
		free(aux);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (chars);
}

char	*read_line(char *chars)
{
	size_t	pos;
	char	*line;

	pos = 0;
	if (chars == NULL)
		return (NULL);
	while (chars[pos] != '\n' && chars[pos] != '\0')
		pos++;
	if (chars[pos] == 0)
		return (NULL);
	line = ft_substr(chars, pos + 1, ft_strlen(chars) - pos);
	if (line == NULL)
		return (NULL);
	chars[pos + 1] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	dstsize;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	lens;

	if (!s)
		return (0);
	lens = ft_strlen(s);
	if (len > lens)
		len = lens;
	if (start + len > lens)
		len = lens - start;
	if (start > lens)
		return (ft_strdup (""));
	substr = (char *)malloc((len + 1));
	if (!substr)
		return (0);
	ft_strlcpy (substr, &s[start], len + 1);
	return (substr);
}