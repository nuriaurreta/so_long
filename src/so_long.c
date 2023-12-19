/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:01:17 by nuria             #+#    #+#             */
/*   Updated: 2023/11/27 14:58:16 by nuria            ###   ########.fr       */
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

int	check_map_name(char *argv)
{
	int	len;
	
	len = ft_strlen(argv) - 1;
	if (len < 5)
		return (1);
	else if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' &&
		argv[len - 3] == '.')
		return(0);
	return (1);
}

int	line_len(t_vars *var)
{
	int	i;

	i = 0;
	while(var->var[i] != '\n' && var->var[i] != '\0')
		i++;
	return (i);
}

int	check_rectangle(t_vars *var)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	var->len = line_len(var) - 1;
	while (var->var)
	{
		while (var->map[i][j] != '\n' && var->map[i][j] != '\0')
		{
			j++;
			if (j != var->len)
				return (1);
			i++;
			j = 0;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	//t_vars	var;

	if (argc != 2)
		return (perror("Error: no map specified.\n"), 1);
	if (check_map_name(argv[1]) == 1)
		return (perror("Error: incorrect map format.\n"), 1);
	printf("el mapa es correcto.n");
	return (0);
}
