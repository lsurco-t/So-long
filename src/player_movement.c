/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:45 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:10 by lsurco-t         ###   ########.fr       */
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
	mlx_image_t	*player_image;

	if (game->player_dir == DIR_UP)
		player_image = game->img_player_up;
	else if (game->player_dir == DIR_DOWN)
		player_image = game->img_player_down;
	else if (game->player_dir == DIR_LEFT)
		player_image = game->img_player_left;
	else
		player_image = game->img_player_right;
	mlx_image_to_window(game->mlx, player_image, game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
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

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height)
		return ;
	if (game->map[new_y][new_x] == WALL)
		return ;
	update_collectibles(game, new_x, new_y);
	exit_status(game);
	if (game->map[new_y][new_x] == EXIT && game->exit_open)
		victory(game);
	game->map[game->player_y][game->player_x] = FLOOR;
	if (game->map[new_y][new_x] != EXIT)
		game->map[new_y][new_x] = PLAYER;
	player_move_count(game, new_x, new_y);
	render_player_update(game);
	render_map(game);
}
