/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:19 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 13:03:15 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_game(t_game *game)
{
	game->map_width = get_columns(game->map);
	game->map_height = get_rows(game->map);
	game->mlx = mlx_init(game->map_width, game->map_height, TITLE, false);
	if(!game->mlx)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize MLX42\n" RESET, 2);
        return (FAIL);
	}
}

int	init_images(t_game *game)
{
}
