/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:30:17 by nuria             #+#    #+#             */
/*   Updated: 2023/11/26 12:32:26 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
	char	**map;
	char	*var;
	size_t	len;
	int		i;
	int		j;

}	t_vars;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}