/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:02:47 by nurreta           #+#    #+#             */
/*   Updated: 2023/12/14 17:14:37 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_key_input(int key, t_game *var)
{
	if (key == KEY_ESC || key == KEY_RIGHT || key == KEY_RIGHT2 
	|| key == KEY_LEFT || key == KEY_LEFT2 || key == KEY_UP || key == KEY_UP2 
	|| key == KEY_DOWN || key == KEY_DOWN2)
	{
	if (key == KEY_ESC)	
	{
		sl_close(var);
		return (0);
	}
	if (key == KEY_RIGHT || key == KEY_RIGHT2)
		sl_move_right(var);
	if (key == KEY_LEFT || key == KEY_LEFT2)
		sl_move_left(var);
	if (key == KEY_UP || key == KEY_UP)
		sl_move_up(var);
	if (key == KEY_DOWN || key == KEY_DOWN2)
		sl_move_down(var);
	free(var->coun);
	var->coun = sl_itoa(var->key_count);
	return (1);
	}
	return (0);
}

int	sl_move_up(t_game *var)
{
	if (var->m.map[var->start_y -1][var->start_x] == '1')
		return (0);
	if (var->m.map[var->start_y -1][var->start_x] == 'C')
		var->m.c_count--;
	if (var->m.map[var->start_y -1][var->start_x] == 'E')
	{
		if (var->m.c_count > 0)
			return (0);
		if (var->m.c_count == 0)
			sl_exit(1, var);
	}
	var->m.map[var->start_y][var->start_x] == '0';
	var->m.map[var->start_y -1][var->start_x] == 'P';
	var->key_count++;
	printf("MOVEMENTS = %i", var->key_count);
	return (0);
}