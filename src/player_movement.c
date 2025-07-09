/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:45 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 23:07:05 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	render_player_update(t_game *game)
{
	game->img_player_up->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player_up->instances[0].y = game->player_y * TILE_SIZE;
	game->img_player_down->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player_down->instances[0].y = game->player_y * TILE_SIZE;
	game->img_player_left->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player_left->instances[0].y = game->player_y * TILE_SIZE;
	game->img_player_right->instances[0].x = game->player_x * TILE_SIZE;
	game->img_player_right->instances[0].y = game->player_y * TILE_SIZE;
	game->img_player_up->enabled = (game->player_dir == DIR_UP);
	game->img_player_down->enabled = (game->player_dir == DIR_DOWN);
	game->img_player_left->enabled = (game->player_dir == DIR_LEFT);
	game->img_player_right->enabled = (game->player_dir == DIR_RIGHT);
}

void	player_move_count(t_game *game, int new_x, int new_y)
{
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Total moves: %d\n", game->moves);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	collected;

	collected = 0;
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == WALL)
		return ;
	if (game->map[new_y][new_x] == COLLECTIBLE)
		collected = 1;
	update_collectibles(game, new_x, new_y);
	exit_status(game);
	if (game->map[new_y][new_x] == EXIT && game->exit_open)
		victory(game);
	game->map[game->player_y][game->player_x] = FLOOR;
	if (game->map[new_y][new_x] != EXIT)
		game->map[new_y][new_x] = PLAYER;
	player_move_count(game, new_x, new_y);
	if (collected && game->img_collectible_map[new_y][new_x])
		game->img_collectible_map[new_y][new_x]->enabled = false;
	render_player_update(game);
}
