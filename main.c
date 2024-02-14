/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:49:41 by nuria             #+#    #+#             */
/*   Updated: 2024/01/02 16:08:04 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_ber(char *argv, t_game *var)
{
	int	len;

	len = sl_strlen(argv) - 1;
	if (len < 5)
		sl_error(9, var);
	if (argv[len] != 'r' || argv[len - 1] != 'e' || argv[len - 2] != 'b'
		|| argv[len - 3] != '.')
		sl_error(9, var);
}

int	main(int argc, char **argv)
{
	t_game	var;
	int		fd;

	sl_init_vars(&var);
	if (argc == 2)
	{
		sl_check_ber(argv[1], &var);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			sl_error(1, &var);
		sl_get_map(fd, argv[1], &var);
		sl_check_pos(&var);
		var.ptr = mlx_init();
		var.win = mlx_new_window(var.ptr, var.size_x, var.size_y, "so_long");
		sl_load_xpm(&var);
		mlx_loop_hook(var.ptr, sl_status, (void *) &var);
		mlx_hook(var.win, 17, 0, sl_close, (void *) &var);
		mlx_key_hook(var.win, sl_key_input, (void *) &var);
		mlx_loop(&var.ptr);
	}
	sl_error(0, &var);
	return (0);
}
