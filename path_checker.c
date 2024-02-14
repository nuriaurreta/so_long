/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:06:09 by nuria             #+#    #+#             */
/*   Updated: 2023/12/22 20:03:15 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_restore_map(char **map, int y, int x, t_game *var)
{
	if (map[y][x] == '1' || map[y][x] < 81)
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = map[y][x] - 40;
		return ;
	}
	map[y][x] = map[y][x] - 40;
	if (y > 0)
		sl_restore_map(map, y - 1, x, var);
	if (y < var->m.map_y - 1)
		sl_restore_map(map, y + 1, x, var);
	if (x > 0)
		sl_restore_map(map, y, x - 1, var);
	if (x < var->m.map_x - 1)
		sl_restore_map(map, y, x + 1, var);
}

void	sl_floodfill(char **map, int y, int x, t_game *var)
{
	if (map[y][x] == '1' || map[y][x] > 80)
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = map[y][x] + 40;
		return ;
	}
	map[y][x] = map[y][x] + 40;
	if (y > 0)
		sl_floodfill(map, y - 1, x, var);
	if (y < var->m.map_y - 1)
		sl_floodfill(map, y + 1, x, var);
	if (x > 0)
		sl_floodfill(map, y, x - 1, var);
	if (x < var->m.map_x - 1)
		sl_floodfill(map, y, x + 1, var);
}

int	sl_check_route(t_game *var)
{
	int	y;
	int	x;

	y = 0;
	while (y < var->m.map_y)
	{
		x = 0;
		while (x < var->m.map_x)
		{
			if (var->m.map[y][x] == 'P' || var->m.map[y][x] == 'E'
				|| var->m.map[y][x] == 'C')
				sl_error(3, var);
			x++;
		}
		y++;
	}
	return (0);
}

int	sl_check_pos(t_game *var)
{
	int	y;
	int	x;

	y = 0;
	while (y < var->m.map_y)
	{
		x = 0;
		while (x < var->m.map_x)
		{
			if (var->m.map[y][x] == 'P')
			{
				sl_floodfill(var->m.map, y, x, var);
				break ;
			}
			x++;
		}
		if (x < var->m.map_x)
			break ;
		y++;
	}
	sl_check_route(var);
	sl_restore_map(var->m.map, y, x, var);
	return (0);
}
