/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pruebas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:28:21 by nuria             #+#    #+#             */
/*   Updated: 2023/11/27 21:21:17 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* typedef struct s_vars
{
	char	**map;
	char	*var;
	size_t	len;
	int		fd;
	int		x;
	int		y;
}	t_vars; */

/* size_t	ft_strlen(const char *str)
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
} */

/* int	check_rectangle(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while ((map)[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			printf("Error\nMap must be a rectangle or a square\n");
			return (1);
		}
		x = 0;
		y++;
	}
	return (0);
} */

int	check_walls(t_vars *map)
{
	int	x;
	//int	y;

	x = 0;
	//y = 0;
	while((*map).map[0][x])
	{
		if ((*map).map[0][x] != '1')
			return (printf("first row KO\n"), 1);	
		x++;
	}
	return (printf("first row OK"), 0);
}

void print_map(char **map) {
	int y = 0;
	while (map[y] != NULL) {
		printf("%s\n", map[y]);
		y++;
	}
}

int main() {
	
	// Ejemplos de mapas para probar
	char *map1[] = {
		"1111101111",
		"1000000001",
		"1000000001",
		"1000000001",
		"1111111111",
		NULL
	};

	/* char *map2[] = {
		"#####",
		"#  #",
		"#   #",
		"#####",
		NULL
	};

	char *map3[] = {
		"###",
		"##",
		NULL
	}; */

	// Probar la función check_rectangle con diferentes mapas
	t_vars vars;
	
    vars.map = map1;
    printf("Mapa 1:\n");
    print_map(map1);
    check_walls(&vars);

	/* printf("\nMapa 2:\n");
	print_map(map2);
	check_rectangle(map2);

	printf("\nMapa 3:\n");
	print_map(map3);
	check_rectangle(map3); */

	return 0;
}

/* int check_read(const char *file_path) 
{
	int fd;
	char buffer[1];
	ssize_t bytes_read;
	
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		return (printf("Error: could not open the file.\n"), 1);
		close(fd);
	}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1) 
	{
		return (printf("Error: could not read the file.\n"),1);
		close(fd);
	}

	if (bytes_read == 0) 
	{
		return (printf("Error: empty map.\n"), 1);
		close(fd);
	}
	close(fd);
	return (0);
}

int main() {
	const char *archivo = "./maps/map1.ber";

	int resultado = check_read(archivo);

	if (resultado == 0) {
		printf("file OK.\n");
	} else {
		printf("file KO.\n");
	}
	return 0;
} */

/* int main(int argc, char **argv)
{
	int	map = 0;
	//t_vars	var;

	if (argc != 2)
		return (printf("Error: no map specified.\n"), 1);
	if (check_map_name(argv[1]) == 1)
		return (printf("Error: incorrect map format.\n"), 1);
	//printf("el mapa es correcto.n");
	map = check_rectangle((char **)map);
	if (map == 1)
	{
		printf("Error: el mapa no es rectangular\n");
		return 1;
	}
	else
		printf("El mapa SÍ es rectangular\n");
	return (0);
} */