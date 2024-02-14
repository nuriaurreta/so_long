/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:46:09 by nurreta           #+#    #+#             */
/*   Updated: 2023/12/22 20:03:42 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_vars(t_game *var)
{
	var->ptr = NULL;
	var->start_x = 0;
	var->start_y = 0;
	var->size_x = 0;
	var->size_y = 0;
	var->time = 0;
	var->key_count = 0;
	var->m.map = NULL;
	var->m.map_x = 0;
	var->m.map_y = 0;
	var->m.c_count = 0;
	var->m.e_count = 0;
	var->m.p_count = 0;
}

int	sl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	sl_write_error(char *s)
{
	write(2, s, sl_strlen(s));
}
