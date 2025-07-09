/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 15:48:23 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collectible_collected(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[game->player_y][game->player_x] = FLOOR;
		mlx_image_to_window(game->mlx, game->img_floor,
			game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
		return (SUCCESS);
	}
	return (FAIL);
}
int	exit_status(t_game *game)
{
	if( game->collectibles == 0 )
	{
		game->exit_open = 1;
		return (SUCCESS);
	}
	else
	{
		game->exit_open = 0;
		return (FAIL);
	}
}
int check_game_won(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == EXIT && game->exit_open)
		return (SUCCESS);
	return (FAIL);
}