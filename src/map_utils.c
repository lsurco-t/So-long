/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:18:27 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 21:57:01 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map_on_error(char **map, int lines)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < lines)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	get_columns(char **map)
{
	int	i;
	int	current_column;
	int	first_column;

	if (!map || !map[0])
		return (FAIL);
	first_column = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		current_column = ft_strlen(map[i]);
		if (current_column != first_column)
			return (FAIL);
		i++;
	}
	return (first_column);
}

int	get_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

int	characters_to_check(char *line, const char *chars)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(chars, line[i]))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}