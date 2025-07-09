/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 16:47:45 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collectible_status(t_game *game, int y, int x)
{
	int new_x;
	int new_y;

	new_x = x;
	new_y = y;
	if(game->map[new_y][new_x] == COLLECTIBLE)
    {
        game->collectibles--;
        game->map[new_y][new_x] = FLOOR;
    }
}

int	exit_status(t_game *game)
{
	if (game->collectibles == 0)
	{
		game->exit_open = 1;
		return (SUCCESS);
	}
	game->exit_open = 0;
	return (FAIL);
}