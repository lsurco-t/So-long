/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:02 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 11:01:54 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	has_valid_walls(char **map)
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

static int	has_valid_start_exit_collec(char **map)
{
	int	start;
	int	exit;
	int	collectible;

	count_game_elements(map, &start, &exit, &collectible);
	if (start != 1 || exit != 1 || collectible < 1)
		return (FAIL);
	return (SUCCESS);
}

static int	has_valid_chars(char **map)
{
	char	*chars;
	int		i;

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

int	validate_map(char **map)
{
	int	columns;

	columns = get_columns(map);
	if (columns == FAIL)
	{
		ft_putstr_fd(RED "Error\nMap is not rectangle!" RESET, 2);
		return (FAIL);
	}
	if (has_valid_chars(map) == FAIL)
	{
		ft_putstr_fd(RED "Error\nInvalid characters!" RESET, 2);
		return (FAIL);
	}
	if (has_valid_start_exit_collec(map) == FAIL)
	{
		ft_putstr_fd(RED "Error\nWrong start, exit or collectible!" RESET, 2);
		return (FAIL);
	}
	if (has_valid_walls(map) == FAIL)
	{
		ft_putstr_fd(RED "Error\nIncomplete walls!" RESET, 2);
		return (FAIL);
	}
	return (SUCCESS);
}
