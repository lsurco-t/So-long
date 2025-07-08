/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:54 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_images(t_game *game)
{
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_delete_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_delete_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_delete_image(game->mlx, game->img_exit);
	if (game->img_player_up)
		mlx_delete_image(game->mlx, game->img_player_up);
	if (game->img_player_down)
		mlx_delete_image(game->mlx, game->img_player_down);
	if (game->img_player_left)
		mlx_delete_image(game->mlx, game->img_player_left);
	if (game->img_player_right)
		mlx_delete_image(game->mlx, game->img_player_right);
}

int	free_and_exit(char **map)
{
	free_map(map);
	return (FAIL);
}
