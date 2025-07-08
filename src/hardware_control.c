/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardware_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:46:24 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 18:40:42 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.key == KEY_D && keydata.action == MLX_PRESS)
    {
        game->player_dir = DIR_RIGHT;
        move_player(game, 1, 0);
    }
    else if (keydata.key == KEY_A && keydata.action == MLX_PRESS)
    {
        game->player_dir = DIR_LEFT;
        move_player(game, -1, 0);
    }
    else if (keydata.key == KEY_W && keydata.action == MLX_PRESS)
    {
        game->player_dir = DIR_UP;
        move_player(game, 0, -1);
    }
    else if (keydata.key == KEY_S && keydata.action == MLX_PRESS)
    {
        game->player_dir = DIR_DOWN;
        move_player(game, 0, 1);
    }
}
