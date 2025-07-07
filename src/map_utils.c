/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:18:27 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 19:50:12 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map_on_error(char **map, int lines)
{
	int i;

	if (!map)
		return;
	i = 0;
	while (i < lines)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}