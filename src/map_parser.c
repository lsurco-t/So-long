/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:36:25 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 23:11:37 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_lines(char *map_path)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**allocate_map(int lines)
{
	char	**map;

	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	map[lines] = NULL;
	return (map);
}

static char	*trim_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static char	**read_map_lines(char *map_path, int lines)
{
	int		fd;
	char	**map;
	char	*current_line;
	int		i;

	map = allocate_map(lines);
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = 0;
	current_line = get_next_line(fd);
	while (current_line != NULL && i < lines)
	{
		trim_newline(current_line);
		map[i] = current_line;
		i++;
		current_line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

char	**parse_map(char *map_path)
{
	int		lines;
	char	**map;
	int		read_lines;

	if (!map_path)
		return (NULL);
	lines = count_lines(map_path);
	if (lines <= 0)
		return (NULL);
	map = read_map_lines(map_path, lines);
	if (!map)
		return (NULL);
	read_lines = 0;
	while (map[read_lines])
		read_lines++;
	if (read_lines != lines)
	{
		free_map_on_error(map, read_lines);
		return (NULL);
	}
	return (map);
}
