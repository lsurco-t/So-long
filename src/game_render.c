/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:31 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 18:01:43 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void render_map(t_game *game)
{
    for (int y = 0; y < game->map_height; y++)
    {
        for (int x = 0; x < game->map_width; x++)
        {
            mlx_image_to_window(game->mlx, game->img_floor, 
                x * TILE_SIZE, y * TILE_SIZE);       
            char tile = game->map[y][x];
            if (tile == '1')
                mlx_image_to_window(game->mlx, game->img_wall, 
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'C')
                mlx_image_to_window(game->mlx, game->img_collectible, 
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'E')
                mlx_image_to_window(game->mlx, game->img_exit, 
                    x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'P')
                mlx_image_to_window(game->mlx, game->img_player_down, 
                    x * TILE_SIZE, y * TILE_SIZE);
        }
    }
}
