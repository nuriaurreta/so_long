/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:29:04 by nuria             #+#    #+#             */
/*   Updated: 2023/12/19 16:40:45 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_temp(char **map, size_t size_y)
{
	size_t	i;

	i = 0;
	while (i < size_y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	sl_check_path(t_game *var, size_t y, size_t x)
{
	if (var->m.map[y][x] == '1')
		return (0);
	if (var->m.map[y][x] == 'C')
		var->m.c_count--;
	if (var->m.map[y][x] == 'E')
	{
		var->exit = 1;
		return (0);
	}
	var->m.map[y][x] ='1';
	if (sl_check_path(var, y + 1, x))
		return (1);
	if (sl_check_path(var, y - 1, x))
		return (1);
	if (sl_check_path(var, y, x + 1))
		return (1);
	if (sl_check_path(var, y, x - 1))
		return (1);
	return (0);
}

void	sl_flood(t_game *var, size_t x, size_t y)
{
	t_game	temp;
	size_t	i;

	temp.size_y = var->size_y;
	temp.size_x = var->size_x;
	temp.m.c_count = var->m.c_count;
	temp.exit = 0;
	temp.m.map = (char **)malloc(temp.size_y * sizeof(char *));
	if (!temp.m.map)
		sl_error(8, var);
	i = 0;
	while (i < temp.size_y)
	{
		temp.m.map[i] = sl_strdup(var->m.map[i]);
		i++;
	}
	sl_check_path(var, y, x);
	if (temp.exit != 1 || temp.m.c_count != 0)
		sl_error(3, var);
	sl_free_temp(temp.m.map, temp.size_y);
}