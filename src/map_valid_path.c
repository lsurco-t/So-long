/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:30:53 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 12:54:26 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**copy_map(char **map)
{
	char	**copy;
	int		rows;
	int		i;

	rows = get_rows(map);
	copy = malloc((rows + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map_on_error(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

static void	get_player_pos(char **map, int *x, int *y)
{
	int	row;
	int	col;

	*x = -1;
	*y = -1;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*x = col;
				*y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

static int	count_collec(char **map)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

static void	floodfill(char **map, t_floodfill params)
{
	t_floodfill	next;

	if (!map || !map[params.y] || !map[params.y][params.x])
		return ;
	if (map[params.y][params.x] == '1' || map[params.y][params.x] == 'V')
		return ;
	if (map[params.y][params.x] == 'C')
		(*params.collec)++;
	else if (map[params.y][params.x] == 'E')
		*params.exit = 1;
	map[params.y][params.x] = 'V';
	next.collec = params.collec;
	next.exit = params.exit;
	next.x = params.x + 1;
	next.y = params.y;
	floodfill(map, next);
	next.x = params.x - 1;
	next.y = params.y;
	floodfill(map, next);
	next.x = params.x;
	next.y = params.y + 1;
	floodfill(map, next);
	next.x = params.x;
	next.y = params.y - 1;
	floodfill(map, next);
}

int	has_valid_path(char **map)
{
	char		**map_copy;
	int			total_collec;
	int			found_collec;
	int			found_exit;
	t_floodfill	fill_params;

	found_collec = 0;
	found_exit = 0;
	map_copy = copy_map(map);
	if (!map_copy)
		return (FAIL);
	get_player_pos(map_copy, &fill_params.x, &fill_params.y);
	if (fill_params.x == -1 || fill_params.y == -1)
	{
		free_map(map_copy);
		return (FAIL);
	}
	total_collec = count_collec(map_copy);
	fill_params.collec = &found_collec;
	fill_params.exit = &found_exit;
	floodfill(map_copy, fill_params);
	free_map(map_copy);
	if (found_collec != total_collec || !found_exit)
		return (FAIL);
	return (SUCCESS);
}
