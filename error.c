/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:20:32 by nuria             #+#    #+#             */
/*   Updated: 2023/12/14 17:00:29 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_error(int n, t_game *var)
{
	if (n == 0)
		sl_write_error("Error\nWrong argument count\n");
	if (n == 1)
		sl_write_error("Error\nCould not open map file\n");
	if (n == 2)
		sl_write_error("Error\nEvery line of the map must have same length\n");
	if (n == 4)
		sl_write_error("Error\nMap must be surrounded by walls (1)\n");
	if (n == 5)
		sl_write_error("Error\nMap must only contain P,C,E,0,1)\n");
	if (n == 6)
		sl_write_error("Error\nThere must be one player & one exit\n");
	if (n == 7)
		sl_write_error("Error\nThere must be at least 1 C\n");
	if (n == 8)
		sl_write_error("Error\nThere was an error allocating memory\n");
	if (n == 9)
		sl_write_error("Error\nThe map is not a .ber file\n");
	sl_exit(0, var);
	return (0);
}

int	sl_close(t_game *var)
{
	sl_exit(2, var);
	return (0);
}

void	sl_destroy(t_game *var)
{
	mlx_destroy_image(var->ptr, var->img.w);
	mlx_destroy_image(var->ptr, var->img.f);
	mlx_destroy_image(var->ptr, var->img.c);
	mlx_destroy_image(var->ptr, var->img.e);
	mlx_destroy_image(var->ptr, var->img.p);
	mlx_clear_window(var->ptr, var->win);
	mlx_destroy_window(var->ptr, var->win);
}

void	sl_free_map(t_game *var)
{
	int	i;

	i = 0;
	while (i < var->m.map_y)
	{
		free(var->m.map[i]);
		i++;
	}
	free(var->m.map[i]);
	free(var->m.map);
}

int	sl_exit(int e, t_game *var)
{
	if (e == 1)
		printf("%sYOU WON! :)\nMOVEMENTS: %d\n%s", G, var->key_count + 1, NC);
	if (e == 2)
		printf("%sYOU QUIT THE GAME WITHOUT FINISHING! :(\n%s", Y, NC);
	//if (e == 3)
	//	printf("%sYOU LOSE! :(\n%s", R, NC);
	if (var->m.map)
		sl_free_map(var);
	if (var->move)
		free(var->move);
	if (var->ptr)
		sl_destroy(var);
	exit(0);
	return (0);
}