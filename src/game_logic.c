/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 18:16:33 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_collectibles(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR;
	}
}

void	exit_status(t_game *game)
{
	if (game->collectibles == 0)
	{
		game->exit_open = 1;
	}
	else
		game->exit_open = 0;
}

int	count_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COLLECTIBLE)
				game->collectibles++;
			x++;
		}
		y++;
	}
	return (game->collectibles);
}

void	victory(t_game *game)
{
	ft_printf(GREEN "Congratulations! You've won the game!\n" RESET);
	cleanup_images(game);
	mlx_terminate(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}