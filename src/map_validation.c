/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:02 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 17:05:26 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int characters_to_check(char *line, char chars)
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

static int is_valid_walls(t_game *game, char *path)
{
	int counter;
}

static int has_valid_start_exit_collec(t_game *game, char *path)
{
	int counter;
}
static int has_valid_chars(const char *path)
{
	int fd;
	char *chars;
	char *line;

	chars = "10CEP";
	fd = open(path, O_RDONLY);
	if (!fd)
		return (FAIL);
	line = get_next_line(fd);
	while(!line)
	{
		if(characters_to_check(line, chars))
		{
			free(line);
			close(fd);
			return (FAIL);
		}
		free(line);
	}
	close(fd);
	return (SUCCESS);
}
int		validate_map(t_game *game, char *map_path)
{
	char *path;

	if (has_valid_chars(path) || has_valid_start_exit_collec(&game, path)
		 || is_valid_walls(&game, path))
	{
		ft_putstr_fd(RED"Error\n Invalid map"RESET,2);
		return (FAIL);
	}
	else
		return (SUCCESS);
}