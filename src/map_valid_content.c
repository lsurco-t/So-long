/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:09:59 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 13:11:05 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	has_valid_walls(char **map)
{
	int	rows;
	int	columns;
	int	i;

	rows = get_rows(map);
	columns = get_columns(map);
	if (rows <= 0 || columns <= 0)
		return (FAIL);
	i = 0;
	while (i < columns)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (FAIL);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][columns - 1] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static void	count_game_elements(char **map, int *start, int *exit, int *collec)
{
	int	i;
	int	j;

	*start = 0;
	*exit = 0;
	*collec = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*start)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				(*collec)++;
			j++;
		}
		i++;
	}
}

int	has_valid_start_exit_collec(char **map)
{
	int	start;
	int	exit;
	int	collectible;

	count_game_elements(map, &start, &exit, &collectible);
	if (start != 1 || exit != 1 || collectible < 1)
		return (FAIL);
	return (SUCCESS);
}

int	has_valid_chars(char **map)
{
	char *chars;
	int i;

	chars = "10CEP";
	i = 0;
	while (map[i])
	{
		if (characters_to_check(map[i], chars))
		{
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
