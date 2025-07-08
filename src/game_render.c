/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 18:59:40 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_player(t_game *game, int x, int y)
{
	if (game->player_dir == DIR_RIGHT)
		mlx_image_to_window(game->mlx, game->img_player_right, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->player_dir == DIR_LEFT)
		mlx_image_to_window(game->mlx, game->img_player_left, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->player_dir == DIR_UP)
		mlx_image_to_window(game->mlx, game->img_player_up, x * TILE_SIZE, y
			* TILE_SIZE);
	else
		mlx_image_to_window(game->mlx, game->img_player_down, x * TILE_SIZE, y
			* TILE_SIZE);
}

void	render_extras(char tile, t_game *game, int x, int y)
{
	if (tile == 'C')
		mlx_image_to_window(game->mlx, game->img_collectible, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y
			* TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y
				* TILE_SIZE);
			tile = game->map[y][x];
			if (tile == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y
					* TILE_SIZE);
			else if (tile == 'C' || tile == 'E')
				render_extras(tile, game, x, y);
			else if (tile == 'P')
				render_player(game, x, y);
			x++;
		}
		y++;
	}
}
