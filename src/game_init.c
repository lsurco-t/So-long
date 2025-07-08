/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:19 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 17:33:18 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_image(mlx_t *mlx, const char *path)
{
	mlx_image_t	*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd(RED "Error\nFailed to load texture: " RESET, 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (NULL);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		ft_putstr_fd(RED "Error\nFailed to convert texture to image\n" RESET, 2);
		return (NULL);
	}
	return (image);
}
int	init_images(t_game *game)
{
	game->img_wall = load_image(game->mlx, "./assets/wall.png");
	if (!game->img_wall)
		return (FAIL);
	game->img_floor = load_image(game->mlx, "./assets/floor.png");
	if (!game->img_floor)
		return (FAIL);
	game->img_collectible = load_image(game->mlx, "./assets/collectible.png");
	if (!game->img_collectible)
		return (FAIL);
	game->img_exit = load_image(game->mlx, "./assets/exit.png");
	if (!game->img_exit)
		return (FAIL);
	game->img_player = load_image(game->mlx, "./assets/player.png");
	if (!game->img_player)
		return (FAIL);
	return (SUCCESS);
}
void	cleanup_images(t_game *game)
{
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_delete_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_delete_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_delete_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
}

int	init_game(t_game *game)
{
	game->map_width = get_columns(game->map);
	game->map_height = get_rows(game->map);
	game->mlx = mlx_init(game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, TITLE, false);
	if (!game->mlx)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize MLX42\n" RESET, 2);
		return (FAIL);
	}
	if (init_game_images(game) == FAIL)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize game images\n" RESET, 2);
		mlx_terminate(game->mlx);
		return (FAIL);
	}
	return (SUCCESS);
}
