/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:07:03 by nurreta           #+#    #+#             */
/*   Updated: 2023/12/13 17:34:07 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_status(t_game *var)
{
	var->time++;
	mlx_clear_window(var->ptr, var->win);
	sl_draw_map(var);
	return(0);
}