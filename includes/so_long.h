/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:42:42 by nuria             #+#    #+#             */
/*   Updated: 2023/11/27 17:21:38 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_vars
{
	char	**map;
	char	*var;
	size_t	len;
	int		i;
	int		j;

}	t_vars;

size_t	ft_strlen(const char *str);
int	check_map_name(char *argv);
int	line_len(t_vars *var);
int	check_rectangle(char **map);

#endif