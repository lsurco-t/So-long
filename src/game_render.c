/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 23:58:54 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_player(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	mlx_image_to_window(game->mlx, game->img_player_up, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->img_player_down, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->img_player_left, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->img_player_right, game->player_x
		* TILE_SIZE, game->player_y * TILE_SIZE);
	game->img_player_up->enabled = (game->player_dir == DIR_UP);
	game->img_player_down->enabled = (game->player_dir == DIR_DOWN);
	game->img_player_left->enabled = (game->player_dir == DIR_LEFT);
	game->img_player_right->enabled = (game->player_dir == DIR_RIGHT);
}

void	render_extras(char tile, t_game *game, int x, int y)
{
	if (tile == COLLECTIBLE)
	{
		game->img_collectible_map[y][x] = load_image(game->mlx,
				"./textures/gem.png");
		if (!game->img_collectible_map[y][x])
			return ;
		mlx_image_to_window(game->mlx, game->img_collectible_map[y][x], x
			* TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == EXIT)
	{
		game->img_exit_map[y][x] = load_image(game->mlx,
				"./textures/groundExit.png");
		if (!game->img_exit_map[y][x])
			return ;
		mlx_image_to_window(game->mlx, game->img_exit_map[y][x], x * TILE_SIZE,
			y * TILE_SIZE);
	}
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
			if (tile == WALL)
				mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y
					* TILE_SIZE);
			else if (tile == COLLECTIBLE || tile == EXIT)
				render_extras(tile, game, x, y);
			x++;
		}
		y++;
	}
}
