/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:10:39 by nuria             #+#    #+#             */
/*   Updated: 2023/12/13 17:33:55 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_get_map(int fd, char *argv, t_game *var)
{
	char	*line;
	int		res;

	res = get_next_line(fd, &line);
	var->m.map_x = sl_strlen(line);
	var->m.map_y = 0;
	while(res >= 0)
	{
		free(line);
		line = NULL;
		var->m.map_y++;
		if (res == 0)
			break ;
		res = get_next_line (fd, &line);
		if (sl_strlen(line) != var->m.map_x)
			sl_error(2, var);
	}
	var->size_x = var->m.map_x * 50;
	var->size_y = var->m.map_y * 50;
	//printf("size_map de x is: %d\n", var->size_x);
	//printf("size_map de y is: %d\n", var->size_y);
	close(fd);
	sl_read_map(fd, argv, var);
}

void	sl_read_map(int fd, char *argv, t_game *var)
{
	char	*line;
	int		res;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	var->m.map = malloc(sizeof(char *) * (var->m.map_y + 1));
	if (!var->m.map)
		sl_error(8, var);
	res = get_next_line(fd, &line);
	//printf("%s\n", line);
	while (res >= 0)
	{
		var->m.map[i] = sl_strdup(line);
		free(line);
		line = NULL;
		if (res == 0)
			break ;
		res = get_next_line(fd, &line);
		//printf("%s\n", line);
		i++;
	}
	var->m.map[++i] = NULL;
	sl_check_walls(var);
	close(fd);
}

void	sl_check_walls(t_game	*var)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < var->m.map_x)
	{
		if (var->m.map[0][j] != '1' 
			|| var->m.map[var->m.map_y - 1][j] != '1')
			sl_error(4, var);
		j++;
	}
	while (i < var->m.map_y)
	{
		if (var->m.map[i][0] != '1'
			|| var->m.map[i][var->m.map_x -1] != '1')
			sl_error(4, var);
		i++;
	}
	//printf("map walls ok");
	sl_check_interior(i, j, var);
}

void	sl_check_interior(int i, int j, t_game	*var)
{
	i = 1;
	j = 1;
	while (i < var->m.map_y)
	{
		j = 0;
		while (j < var->m.map_x)
		{
			if (!(sl_strchr("PCE01", var->m.map[i][j])))
				sl_error(5, var);
			if (var->m.map[i][j] == 'E')
				var->m.e_count++;
			if (var->m.map[i][j] == 'P')
				var->m.p_count++;
			if (var->m.map[i][j] == 'C')
				var->m.c_count++;
			j++;
		}
		i++;
	}
	if (var->m.e_count != 1 || var->m.p_count != 1)
		sl_error(6, var);
	if (var->m.c_count < 1)
		sl_error(7, var);
	//printf("e_count: %i\n", var->m.e_count);
	//printf("p_count: %i\n", var->m.p_count);
	//printf("c_count: %i\n", var->m.c_count);
}
