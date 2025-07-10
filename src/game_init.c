/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:51:19 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/10 18:25:01 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_image(mlx_t *mlx, char *path)
{
	mlx_image_t		*image;
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
		ft_putstr_fd(RED "Error\nFailed to convert texture to image\n" RESET,
			2);
		return (NULL);
	}
	return (image);
}

static int	init_player_images(t_game *game)
{
	game->img_player_up = load_image(game->mlx, "./textures/walk_up.png");
	if (!game->img_player_up)
		return (FAIL);
	game->img_player_down = load_image(game->mlx, "./textures/walk_down.png");
	if (!game->img_player_down)
		return (FAIL);
	game->img_player_left = load_image(game->mlx, "./textures/walk_left.png");
	if (!game->img_player_left)
		return (FAIL);
	game->img_player_right = load_image(game->mlx, "./textures/walk_right.png");
	if (!game->img_player_right)
		return (FAIL);
	return (SUCCESS);
}

static int	init_collectible_exit_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == COLLECTIBLE)
				game->img_collectible_map[y][x] = load_image(game->mlx,
						"./textures/gem.png");
			if (game->map[y][x] == EXIT)
				game->img_exit_map[y][x] = load_image(game->mlx,
						"./textures/groundExit.png");
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

static int	init_background_images(t_game *game)
{
	game->img_wall = load_image(game->mlx, "./textures/wallStone_fence.png");
	if (!game->img_wall)
		return (FAIL);
	game->img_floor = load_image(game->mlx, "./textures/floor.png");
	if (!game->img_floor)
		return (FAIL);
	game->img_collectible = load_image(game->mlx, "./textures/gem.png");
	if (!game->img_collectible)
		return (FAIL);
	game->img_exit = load_image(game->mlx, "./textures/groundExit.png");
	if (!game->img_exit)
		return (FAIL);
	if (init_collectible_exit_images(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	init_game(t_game *game)
{
	game->map_width = get_columns(game->map);
	game->map_height = get_rows(game->map);
	game->player_dir = DIR_DOWN;
	if (game->map_width <= 0 || game->map_height <= 0)
		return (FAIL);
	game->mlx = mlx_init(game->map_width * TILE_SIZE, game->map_height
			* TILE_SIZE, TITLE, false);
	if (!game->mlx)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize MLX42\n" RESET, 2);
		return (FAIL);
	}
	if (init_background_images(game) == FAIL)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize background\n" RESET, 2);
		return (FAIL);
	}
	if (init_player_images(game) == FAIL)
	{
		ft_putstr_fd(RED "Error\nFailed to initialize player images\n" RESET,
			2);
		return (FAIL);
	}
	return (SUCCESS);
}
