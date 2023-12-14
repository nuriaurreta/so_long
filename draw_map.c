/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:09:59 by nurreta           #+#    #+#             */
/*   Updated: 2023/12/13 15:33:52 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_map(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->m.map[i] != NULL)
	{
		j = 0;
		while (var->m.map[i][j] != '\0')
		{
			mlx_put_image_to_window(var->ptr, var->win, var->img.f,
			50 * j, 50 * i);
			sl_map_to_window(i, j, var);
			j++;
		}
		i++;
	}
}

void	sl_map_to_window(int i, int j, t_game *var)
{
	if (var->m.map[i][j] == '1')
		mlx_put_image_to_window(var->ptr, var->win, var->img.w, 50 * j, 50 * i);
	else
		mlx_put_image_to_window(var->ptr, var->win, var->img.f, 50 * j, 50 * i);
	if (var->m.map[i][j] == 'C')
		mlx_put_image_to_window(var->ptr, var->win, var->img.c, 50 * j, 50 * i);
	if (var->m.map[i][j] == 'P')
	{
		mlx_put_image_to_window(var->ptr, var->win, var->img.p, 50 * j, 50 * i);
		var->start_x = j;
		var->start_y = i;
	}
	if (var->m.map[i][j] == 'E')
			mlx_put_image_to_window(var->ptr, var->win,
			var->img.e, 50 * j, 50 * i);
}