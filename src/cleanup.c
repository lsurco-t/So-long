/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:32 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/10 21:01:01 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup_images_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->img_collectible_map[y][x])
				mlx_delete_image(game->mlx, game->img_collectible_map[y][x]);
			x++;
		}
		y++;
	}
}

void	cleanup_images(t_game *game)
{
	cleanup_images_map(game);
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

int	free_and_exit_with_cleanup(t_game *game)
{
	if (!game)
		return (FAIL);
	cleanup_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
	return (FAIL);
}

void	free_map_mlx(t_game *game)
{
	if (!game)
		return ;
	cleanup_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game->map);
}

int	print_error_return(int err)
{
	if (err == 1)
		ft_putstr_fd(RED "Error\nUsage ./so_long /maps/xxx.ber\n" RESET, 2);
	else if (err == 2)
		ft_putstr_fd(RED "Error\nMap file is not a valid .ber file\n" RESET, 2);
	return (FAIL);
}
