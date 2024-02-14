/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:37:38 by nuria             #+#    #+#             */
/*   Updated: 2024/01/02 18:08:18 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

static int	sl_read_line(int fd, char **line, char **saved, int file_size)
{
	char	*aux;
	int		len;

	if (!file_size && !saved[fd])
		*line = sl_strdup("");
	else
	{
		len = sl_line_length(saved[fd]);
		if (saved[fd][len] == '\n')
		{
			*line = sl_substr(saved[fd], 0, len);
			aux = sl_strdup(saved[fd] + len + 1);
			free(saved[fd]);
			saved[fd] = aux;
			return (1);
		}
		else
			*line = sl_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[4096];
	int			file_size;
	char		buff[BUFFER_SIZE + 1];
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	file_size = read(fd, buff, BUFFER_SIZE);
	while (file_size > 0)
	{
		buff[file_size] = '\0';
		if (!saved[fd])
			saved[fd] = sl_strdup("");
		aux = sl_strjoin(saved[fd], buff);
		free(saved[fd]);
		saved[fd] = aux;
		if (sl_strchr(buff, '\n'))
			break ;
		file_size = read(fd, buff, BUFFER_SIZE);
	}
	if (file_size == -1)
		return (-1);
	return (sl_read_line(fd, line, saved, file_size));
}
