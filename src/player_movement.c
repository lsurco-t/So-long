/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:45 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 19:18:06 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_player_position(t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
void	move_player(t_game *game, int dx, int dy)
{
    int	new_x = game->player_x + dx;
    int	new_y = game->player_y + dy;

    // Check bounds
    if (new_x < 0 || new_x >= game->map_width || new_y < 0 || new_y >= game->map_height)
        return;
    // Check for wall
    if (game->map[new_y][new_x] == WALL)
        return;

    // Remove player from old position
    game->map[game->player_y][game->player_x] = FLOOR;
    // Place player at new position
    game->map[new_y][new_x] = PLAYER;
    game->player_x = new_x;
    game->player_y = new_y;
    game->moves++;

    render_map(game);
}
