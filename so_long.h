/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nurreta <nurreta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:29 by nuria             #+#    #+#             */
/*   Updated: 2023/12/19 16:17:51 by nurreta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* Define BUFF size for GNL, Key values & colors */

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

/* Declare structs */

typedef struct s_map
{
	char	**map;
	size_t	map_x;
	size_t	map_y;
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
	size_t	size_x;
	size_t	size_y;
	size_t	start_x;
	size_t	start_y;
	size_t	time;
	size_t	key_count;
	size_t	exit;
	char	*coun;
	char	*move;
	t_image	img;
	t_map	m;
}	t_game;

/*functions*/

// utils
void	sl_init_vars(t_game *var);
size_t	sl_strlen(const char *str);
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
void	sl_check_interior(size_t y, size_t x, t_game *var);
int		sl_check_path(t_game *temp, size_t y, size_t x);
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
// Check path
int		sl_check_path(t_game *var, size_t y, size_t x);
void	sl_flood(t_game *var, size_t x, size_t y);

#endif