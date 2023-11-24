/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:26 by nurreta           #+#    #+#             */
/*   Updated: 2023/11/21 18:51:06 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./mlx/mlx.h"

typedef struct s_cell
{
	int		len;
	int		map_ok;
	int		i;
	int		j;
	int		wall;
	int		coll;
	int		exit;
	int		player;
	int		empty;

}	t_cell;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_name(char **argv)
{
	int len;
	len = ft_strlen (argv);
	if (len < 5)
		return(-1);
	if (argv[len - 1] == "r" && argv[len - 2] == "e" &&
		argv[len - 3] == "b" && argv[1][len - 4] == ".")
			return (len);
}

void	error(t_cell *vars)
{
	printf("Error %d", vars->map_ok);
}

int	check_file(t_cell *vars, char **argv)
{
	vars->map_ok = check_name(argv);
	return (vars->map_ok);
} 

int main(int argc, char **argv)
{
	t_cell	vars;

	if (argc != 2)
		return (write(2, "Error. Falta el primer argumento\n", 34), 0);
	vars.map_ok = check_file (&vars, argv);
	if (vars.map_ok != 0)
		return (error(&vars), 0);
}