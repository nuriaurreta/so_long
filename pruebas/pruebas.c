/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuria <nuria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 02:33:28 by ldurante          #+#    #+#             */
/*   Updated: 2023/12/03 12:51:21 by nuria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pruebas.h"
#include <stdlib.h>

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->m.map_y)
	{
		free(g->m.map[i]);
		i++;
	}
	free(g->m.map[i]);
	free(g->m.map);
}

int	ft_exit(int e, t_game *var)
{
	if (e == 1)
		printf("%sYOU WON! :)\nMOVEMENTS: %d\n%s", G, var->key_count + 1, NC);
	if (e == 2)
		printf("%sYOU QUIT THE GAME WITHOUT FINISHING! :(\n%s", Y, NC);
	if (e == 3)
		printf("%sYOU LOSE! NO NUTELLA FOR YOU :(\n%s", R, NC);
	if (var->m.map)
		free_map(var);
	if (var->move)
		free(var->move);
	/* if (var->ptr)
		ft_destroy(var); */
	exit(0);
	return (0);
}

int	ft_error(int n, t_game *g)
{
	if (n == 0)
		printf("Error\nWrong argument count\n");
	if (n == 1)
		printf("Error\nCould not open map file\n");
	if (n == 2)
		printf("Error\nEvery line of the map must have the same length\n");
	if (n == 3)
		printf("Error\nThe map must be a rectangle\n");
	if (n == 4)
		printf("Error\nMap must be surrounded by walls (1)\n");
	if (n == 5)
		printf("Error\nMap must only contain correct characters (PCE01)\n");
	if (n == 6)
		printf("Error\nThere must be only one player & one exit\n");
	if (n == 7)
		printf("Error\nThere must be at least 1 player, 1 exit and 1 collect\n");
	if (n == 8)
		printf("Error\nThere was an error allocating memory\n");
	if (n == 9)
		printf("Error\nThe map is not a .ber file\n");
	ft_exit(0, g);
	return (0);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;

	i = 0;
	c1 = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)(s + i));
		i++;
	}
	if (!c1)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < dstsize)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*scopia;

	scopia = malloc(ft_strlen(s1) + 1);
	if (scopia == NULL)
		return (NULL);
	ft_strlcpy (scopia, s1, ft_strlen(s1) + 1);
	return (scopia);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	dstsize;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(dstsize);
	if (!newstr)
		return (NULL);
	i = 0;
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	lens;

	lens = ft_strlen(s);
	if (len > lens)
		len = lens;
	if (start + len > lens)
		len = lens - start;
	if (start > lens)
		return (ft_strdup (""));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	ft_strlcpy (substr, &s[start], len + 1);
	return (substr);
}


int	ft_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

int	ft_read_line(int fd, char **line, char **saved, int file_size)
{
	char	*aux;
	int		len;

	if (!file_size && !saved[fd])
		*line = ft_strdup("");
	else
	{
		len = ft_line_length(saved[fd]);
		if (saved[fd][len] == '\n')
		{
			*line = ft_substr(saved[fd], 0, len);
			aux = ft_strdup(saved[fd] + len + 1);
			free(saved[fd]);
			saved[fd] = aux;
			return (1);
		}
		else
			*line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[4096];
	int			file_size;
	char		buff[BUFFER_SIZE + 1];
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	file_size = read(fd, buff, BUFFER_SIZE);
	while (file_size > 0)
	{
		buff[file_size] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup("");
		aux = ft_strjoin(saved[fd], buff);
		free(saved[fd]);
		saved[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
		file_size = read(fd, buff, BUFFER_SIZE);
	}
	if (file_size == -1)
		return (-1);
	return (ft_read_line(fd, line, saved, file_size));
}

/* void	get_map(int fd, char *argv, t_game *var)
{
	char	*line;
	int		res;

	res = get_next_line(fd, &line);
	var->m.map_x = ft_strlen(line);
	var->m.map_y = 0;
	while(res >= 0)
	{
		free(line);
		line = NULL;
		var->m.map_y++;
		if (res == 0)
			break ;
		res = get_next_line (fd, &line);
		if (ft_strlen(line) != var->m.map_x)
			printf("Error, no es rectangular");
	}
	var->size_x = var->m.map_x * 50;
	var->size_y = var->m.map_y * 50;
	printf("El mapa es rectangular");

	close(fd);
} */

void	read_map(int fd, char *argv,  t_game *var)
{
	char	*line;
	int		res;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	var->m.map = malloc(sizeof(char *) * (var->m.map_y + 1));
	if (!var->m.map)
		ft_error(8, var);
	res = get_next_line(fd, &line);
	while (res >= 0)
	{
		var->m.map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		if (res == 0)
			break ;
		res = get_next_line(fd, &line);
		i++;
	}
	var->m.map[++i] = NULL;
	//check_walls(var);
	close(fd);
}

// main para probar 'read_map'
int main() {
	char *argv = "pruebas.ber";
	int fd = open(argv, O_RDONLY);
	t_game g;
	
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return 1;
	}


	// Llama a la función get_map con el descriptor de archivo y la estructura t_game
	read_map(fd, argv, &g);

	int i = 0;
    while (g.m.map[i] != NULL) {
        printf("%s\n", g.m.map[i]);
        i++;
    }
	// Cierra el descriptor de archivo después de su uso
	close(fd);
	return 0;
}
// main para probar 'get_map'
/* int main() {
	int fd = open("pruebas.ber", O_RDONLY);
	
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return 1;
	}

	// Definir una variable de tipo t_game para pasar a get_map
	t_game game_data;

	// Llama a la función get_map con el descriptor de archivo y la estructura t_game
	get_map(fd, &game_data);

	// Cierra el descriptor de archivo después de su uso
	close(fd);

	printf("map_x: %d\n", game_data.m.map_x);
	printf("map_y: %d\n", game_data.m.map_y);
	printf("size_x: %d\n", game_data.size_x);
	printf("size_y: %d\n", game_data.size_y);

	return 0;
} */

// main para probar gnl
/* int main(void)
{
	int fd;
	char *line;
	
	
	// Reemplaza "nombre_de_tu_archivo.txt" con el nombre de tu archivo
	fd = open("pruebas.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	int ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret >= 0)
		{
			printf("Linea leída: %s\n", line);
			free(line);
		}
		if (ret == -1)
		{
			perror("Error al leer la línea");
			free(line);
			close(fd);
			return (1);
		}
	}
	get_map(fd, var);

	close(fd);
	return (0);
} */
