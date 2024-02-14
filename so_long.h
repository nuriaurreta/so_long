/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:29 by nuria             #+#    #+#             */
/*   Updated: 2024/01/08 15:39:04 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10
# define KEY_UP 13
# define KEY_UP2 126
# define KEY_DOWN 1
# define KEY_DOWN2 125
# define KEY_LEFT 0
# define KEY_LEFT2 123
# define KEY_RIGHT 2
# define KEY_RIGHT2 124
# define KEY_ESC 53
# define G "\033[0;32m"
# define Y "\033[0;33m"
# define NC "\033[0m"

typedef struct s_map
{
	char	**map;
	int		map_x;
	int		map_y;
	int		c_count;
	int		p_count;
	int		e_count;
}	t_map;

typedef struct s_image
{
	int		tile_x;
	int		tile_y;
	void	*w;
	void	*c;
	void	*p;
	void	*e;
	void	*f;
}	t_image;

typedef struct s_game
{
	void	*ptr;
	void	*win;
	int		size_x;
	int		size_y;
	size_t	start_x;
	size_t	start_y;
	size_t	time;
	size_t	key_count;
	t_image	img;
	t_map	m;
}	t_game;

/*functions*/

// utils
void	sl_init_vars(t_game *var);
int		sl_strlen(const char *str);
void	sl_write_error(char *s);
// error
int		sl_error(int n, t_game *var);
int		sl_close(t_game *var);
void	sl_destroy(t_game *var);
void	sl_free_map(t_game *var);
int		sl_exit(int e, t_game *var);
// libft utils
char	*sl_strchr(const char *s, int c);
char	*sl_strdup(const char *s1);
char	*sl_strjoin(char *s1, char *s2);
char	*sl_substr(char const *s, unsigned int start, size_t len);
size_t	sl_strlcpy(char *dst, const char *src, size_t dstsize);
// get next line
int		get_next_line(int fd, char **line);
// check map
void	sl_check_ber(char *argv, t_game *var);
void	sl_get_map(int fd, char *argv, t_game *var);
void	sl_read_map(int fd, char *argv, t_game *var);
void	sl_check_walls(t_game	*var);
void	sl_check_interior(int y, int x, t_game *var);
// check path
int		sl_check_pos(t_game *var);
int		sl_check_route(t_game *var);
void	sl_floodfill(char **map, int y, int x, t_game *var);
void	sl_restore_map(char **map, int y, int x, t_game *var);
// map
void	sl_draw_map(t_game *var);
void	sl_map_to_window(int i, int j, t_game *var);
void	sl_load_xpm(t_game *var);
int		sl_status(t_game *var);
// key input
int		sl_key_input(int key, t_game *var);
int		sl_move_up(t_game *var);
int		sl_move_down(t_game *var);
int		sl_move_left(t_game *var);
int		sl_move_right(t_game *var);

#endif