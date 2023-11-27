/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:33 by nuria             #+#    #+#             */
/*   Updated: 2023/11/27 19:19:55 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
	char	**map;
	char	*var;
	size_t	len;
}	t_vars;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_map_name(char *argv)
{
	int	len;
	
	len = ft_strlen(argv) - 1;
	if (len < 5)
		return (1);
	else if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' &&
		argv[len - 3] == '.')
		return(0);
	return (1);
}

int	check_rectangle(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			printf("Error\nMap must be a rectangle or a square\n");
			return (1);
		}
		x = 0;
		y++;
	}
	return (0);
}

int check_read(const char *file_path) 
{
	int fd;
	char buffer[1];
	ssize_t bytes_read;
	
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		return (printf("Error: could not open the file.\n"), 1);
		close(fd);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1) 
	{
		return (printf("Error: could not read the file.\n"),1);
		close(fd);
	}
	if (bytes_read == 0) 
	{
		return (printf("Error: empty map.\n"), 1);
		close(fd);
	}
	close(fd);
	return (0);
}