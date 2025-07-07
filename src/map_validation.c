/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:02 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 20:49:22 by lsurco-t         ###   ########.fr       */
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

static int is_valid_walls(const char *map)
{
	int counter;
}

static int has_valid_start_exit_collec(const char *map)
{
	int counter;
}
static int has_valid_chars(const char **map)
{
	char *line;
	char *chars;
	int i;
	
	chars = "10CEP\n";
	i = 0;
	while(map[i])
	{
		if(characters_to_check(map[i], chars))
			return (FAIL);
	}
	return (SUCCESS);
}
int		validate_map(char **map)
{
	if (has_valid_chars(map))
	{
		ft_putstr_fd(RED"Error\nInvalid characters!"RESET,2);
		return (FAIL);
	}
	else if (has_valid_start_exit_collec(map))
	{
		ft_putstr_fd(RED"Error\nMissing start, exit or collectible!"RESET,2);
		return (FAIL);
	}
	else if (is_valid_walls(map))
	{
		ft_putstr_fd(RED"Error\nIncomplete walls!"RESET,2);
		return (FAIL);
	}
	else
		return (SUCCESS);
}
