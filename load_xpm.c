/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:31:05 by nuria             #+#    #+#             */
/*   Updated: 2023/12/13 17:37:46 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_load_xpm(t_game *var)
{
	var->img.w = mlx_xpm_file_to_image(var->ptr, "textures/wall.xpm",
			&var->img.tile_x, &var->img.tile_y);
	var->img.c = mlx_xpm_file_to_image(var->ptr, "textures/coll.xpm",
			&var->img.tile_x, &var->img.tile_y);
	var->img.p = mlx_xpm_file_to_image(var->ptr, "textures/player.xpm",
			&var->img.tile_x, &var->img.tile_y);
	var->img.e = mlx_xpm_file_to_image(var->ptr, "textures/exit.xpm",
			&var->img.tile_x, &var->img.tile_y);
	var->img.f = mlx_xpm_file_to_image(var->ptr, "textures/floor.xpm",
			&var->img.tile_x, &var->img.tile_y);
}