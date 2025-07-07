/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:02 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 18:23:41 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int characters_to_check(char *line, const char *chars)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (!ft_strchr(chars, line[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int is_valid_walls(const char *path)
{
	int counter;
}

static int has_valid_start_exit_collec(const char *path)
{
	int counter;
}
static int has_valid_chars(const char *path)
{
	int fd;
	char *chars;
	char *line;
	int	invalid_count;

	chars = "10CEP\n";
	invalid_count = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	line = get_next_line(fd);
	while(line)
	{
		if(characters_to_check(line, chars))
			invalid_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if(invalid_count > 0)
		return (FAIL);
	return (SUCCESS);
}
int		validate_map(char **map_path)
{
	if (has_valid_chars(map_path))
	{
		ft_putstr_fd(RED"Error\nInvalid characters!"RESET,2);
		return (FAIL);
	}
	else if (has_valid_start_exit_collec(map_path))
	{
		ft_putstr_fd(RED"Error\nMissing start, exit or collectible!"RESET,2);
		return (FAIL);
	}
	else if (is_valid_walls(map_path))
	{
		ft_putstr_fd(RED"Error\nIncomplete walls!"RESET,2);
		return (FAIL);
	}
	else
		return (SUCCESS);
}
