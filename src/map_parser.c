/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:36:25 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 19:56:14 by lsurco-t         ###   ########.fr       */
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
		return (FAIL);
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
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	map[lines] = '\0';
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
static char	is_lines_read(int indx, char *line, char **map)
{
	if (indx != line)
	{
		free_map_on_error(map, indx);
		return (NULL);
	}
}
char	**parse_map(char *map_path)
{
	int		fd;
	char	**map;
	char	*current_line;
	int		lines;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = count_lines(map_path);
	if (lines <= 0)
		return (NULL);
	map = allocate_map(lines);
	if (!map)
		return (NULL);
	current_line = get_next_line(fd);
	while (current_line != NULL && i < lines)
	{
		trim_newline(current_line);
		map[i++] = current_line;
		current_line = get_next_line(fd);
	}
	close(fd);
	is_lines_read(i, lines, map);
	return (map);
}
