/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:23:16 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/05 21:58:25 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Window constants
# define WIDTH 800
# define HEIGHT 600
# define TITLE "So Long"

// Game elements
# define WALL		'1'
# define FLOOR		'0'
# define COLLECTIBLE	'C'
# define EXIT		'E'
# define PLAYER		'P'

// Key codes for MLX42
# define KEY_W		MLX_KEY_W
# define KEY_A		MLX_KEY_A
# define KEY_S		MLX_KEY_S
# define KEY_D		MLX_KEY_D
# define KEY_ESC	MLX_KEY_ESCAPE

// Tile size in pixels
# define TILE_SIZE	32

// Game structure
typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_collectible;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	int			exit_open;
}	t_game;

// Function prototypes
int		main(int argc, char **argv);
int		parse_map(t_game *game, char *filename);
int		validate_map(t_game *game);
int		init_game(t_game *game);
int		init_images(t_game *game);
void	render_map(t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	key_hook(mlx_key_data_t keydata, void *param);
void	cleanup_game(t_game *game);
void	ft_error(const char *message);

#endif