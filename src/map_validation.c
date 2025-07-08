/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:02 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 13:24:15 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	validate_content(char **map)
{
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

static int	validate_structure(char **map)
{
	int	columns;

	columns = get_columns(map);
	if (columns == FAIL)
	{
		ft_putstr_fd(RED "Error\nMap is not rectangle!" RESET, 2);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	validate_playability(char **map)
{
	if (has_valid_path(map) == FAIL)
	{
		ft_putstr_fd(RED "Error\nMap has not valid path!" RESET, 2);
		return (FAIL);
	}
	return (SUCCESS);
}

int	validate_map(char **map)
{
	if (!map || map[0])
		return (FAIL);
	if (validate_content(map) == FAIL)
		return (FAIL);
	if (validate_structure(map) == FAIL)
		return (FAIL);
	if (validate_playability(map == FAIL))
		return (FAIL);
	return (SUCCESS);
}
