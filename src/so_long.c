/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/06 16:41:24 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(const char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == KEY_ESC && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == KEY_W)
			move_player(game, game->player_x, game->player_y - 1);
		else if (keydata.key == KEY_S)
			move_player(game, game->player_x, game->player_y + 1);
		else if (keydata.key == KEY_A)
			move_player(game, game->player_x - 1, game->player_y);
		else if (keydata.key == KEY_D)
			move_player(game, game->player_x + 1, game->player_y);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	char	target_tile;

	// Check bounds
	if (new_x < 0 || new_x >= game->map_width || 
		new_y < 0 || new_y >= game->map_height)
		return ;
	
	target_tile = game->map[new_y][new_x];
	
	// Check if target is a wall
	if (target_tile == WALL)
		return ;
	
	// Move player image
	game->img_player->instances[0].x = new_x * TILE_SIZE;
	game->img_player->instances[0].y = new_y * TILE_SIZE;
	
	// Update player position
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	
	ft_printf("Moves: %d\n", game->moves);
	
	// Check for collectible
	if (target_tile == COLLECTIBLE)
	{
		game->collectibles--;
		game->map[new_y][new_x] = FLOOR; // Remove collectible from map
		if (game->collectibles == 0)
			game->exit_open = 1;
	}
	
	// Check for exit
	if (target_tile == EXIT && game->exit_open)
	{
		ft_printf("Congratulations! You completed the game in %d moves!\n", game->moves);
		mlx_close_window(game->mlx);
	}
}

int	init_images(t_game *game)
{
	// For now, we'll create colored rectangles as placeholders
	// In a full implementation, you would load actual textures
	
	game->img_wall = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	game->img_floor = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	game->img_collectible = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	game->img_exit = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	game->img_player = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
	
	if (!game->img_wall || !game->img_floor || !game->img_collectible ||
		!game->img_exit || !game->img_player)
		return (0);
	
	// Fill images with colors (placeholder graphics)
	// Wall - Brown
	for (int y = 0; y < TILE_SIZE; y++)
		for (int x = 0; x < TILE_SIZE; x++)
			mlx_put_pixel(game->img_wall, x, y, 0x8B4513FF);
	
	// Floor - Light gray
	for (int y = 0; y < TILE_SIZE; y++)
		for (int x = 0; x < TILE_SIZE; x++)
			mlx_put_pixel(game->img_floor, x, y, 0xD3D3D3FF);
	
	// Collectible - Yellow
	for (int y = 0; y < TILE_SIZE; y++)
		for (int x = 0; x < TILE_SIZE; x++)
			mlx_put_pixel(game->img_collectible, x, y, 0xFFFF00FF);
	
	// Exit - Green
	for (int y = 0; y < TILE_SIZE; y++)
		for (int x = 0; x < TILE_SIZE; x++)
			mlx_put_pixel(game->img_exit, x, y, 0x00FF00FF);
	
	// Player - Blue
	for (int y = 0; y < TILE_SIZE; y++)
		for (int x = 0; x < TILE_SIZE; x++)
			mlx_put_pixel(game->img_player, x, y, 0x0000FFFF);
	
	return (1);
}

void	render_map(t_game *game)
{
	int	x, y;
	
	for (y = 0; y < game->map_height; y++)
	{
		for (x = 0; x < game->map_width; x++)
		{
			// Always draw floor first
			mlx_image_to_window(game->mlx, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			
			// Then draw the specific tile
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == COLLECTIBLE)
				mlx_image_to_window(game->mlx, game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == EXIT)
				mlx_image_to_window(game->mlx, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == PLAYER)
			{
				mlx_image_to_window(game->mlx, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
				game->player_x = x;
				game->player_y = y;
			}
		}
	}
}

int	init_game(t_game *game)
{
	int	window_width, window_height;
	
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	
	game->mlx = mlx_init(window_width, window_height, TITLE, true);
	if (!game->mlx)
	{
		ft_error(mlx_strerror(mlx_errno));
		return (0);
	}
	
	if (!init_images(game))
	{
		ft_error("Failed to initialize images");
		return (0);
	}
	
	render_map(game);
	
	// Set up key hook
	mlx_key_hook(game->mlx, &key_hook, game);
	
	return (1);
}

// Basic map parsing (you'll need to implement this properly)
int	parse_map(t_game *game, char *filename)
{
	// This is a simple example - you'll need to implement proper map parsing
	// For now, let's create a simple test map
	(void)filename; // Suppress unused parameter warning
	
	game->map_width = 5;
	game->map_height = 5;
	game->collectibles = 2;
	game->moves = 0;
	game->exit_open = 0;
	
	// Allocate map
	game->map = malloc(sizeof(char *) * game->map_height);
	if (!game->map)
		return (0);
	
	// Simple test map
	game->map[0] = ft_strdup("11111");
	game->map[1] = ft_strdup("1P0C1");
	game->map[2] = ft_strdup("10101");
	game->map[3] = ft_strdup("1C0E1");
	game->map[4] = ft_strdup("11111");
	
	return (1);
}

void	cleanup_game(t_game *game)
{
	int	i;
	
	if (game->map)
	{
		for (i = 0; i < game->map_height; i++)
			free(game->map[i]);
		free(game->map);
	}
	
	if (game->mlx)
		mlx_terminate(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	
	// Initialize game structure
	ft_memset(&game, 0, sizeof(t_game));
	
	// Parse map
	if (!parse_map(&game, argv[1]))
		ft_error("Failed to parse map");
	
	// Initialize game
	if (!init_game(&game))
	{
		cleanup_game(&game);
		return (1);
	}
	
	// Start game loop
	mlx_loop(game.mlx);
	
	// Cleanup
	cleanup_game(&game);
	
	return (0);
}