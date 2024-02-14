/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:10:39 by nuria             #+#    #+#             */
/*   Updated: 2023/12/22 19:50:44 by nuria            ###   ########.fr       */
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
	while (res >= 0)
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
	while (res >= 0)
	{
		var->m.map[i] = sl_strdup(line);
		free(line);
		line = NULL;
		if (res == 0)
			break ;
		res = get_next_line(fd, &line);
		i++;
	}
	var->m.map[++i] = NULL;
	sl_check_walls(var);
	close(fd);
}

void	sl_check_walls(t_game	*var)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (x < var->m.map_x)
	{
		if (var->m.map[0][x] != '1'
			|| var->m.map[var->m.map_y - 1][x] != '1')
			sl_error(4, var);
		x++;
	}
	while (y < var->m.map_y)
	{
		if (var->m.map[y][0] != '1'
			|| var->m.map[y][var->m.map_x -1] != '1')
			sl_error(4, var);
		y++;
	}
	sl_check_interior(y, x, var);
}

void	sl_check_interior(int y, int x, t_game *var)
{
	y = 1;
	x = 1;
	while (y < var->m.map_y)
	{
		x = 0;
		while (x < var->m.map_x)
		{
			if (!(sl_strchr("PCE01", var->m.map[y][x])))
				sl_error(5, var);
			if (var->m.map[y][x] == 'E')
				var->m.e_count++;
			if (var->m.map[y][x] == 'P')
				var->m.p_count++;
			if (var->m.map[y][x] == 'C')
				var->m.c_count++;
			x++;
		}
		y++;
	}
	if (var->m.e_count != 1 || var->m.p_count != 1)
		sl_error(6, var);
	if (var->m.c_count < 1)
		sl_error(7, var);
}
