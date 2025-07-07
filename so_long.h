/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:23:16 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 23:13:38 by lsurco-t         ###   ########.fr       */
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
# include <errno.h>
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

// Colors
#define GREEN	"\033[0;32m"
#define RED		"\033[0;31m"
#define BLUE	"\033[0;34m"
#define RESET 	"\033[0m"

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

// RETURN CODE
#define SUCCESS 0
#define FAIL 1

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
	int			collectibles;
	int			moves;
	int			exit_open;
}	t_game;

// Map utils

void	free_map_on_error(char **map, int lines);
char	**parse_map(char *filename);
void	free_map(char **map);
int		get_rows(char **map);
int		get_columns(char **map);
int		characters_to_check(char *line, const char *chars);

int		validate_map(char **game);


int		init_game(t_game *game);
int		init_images(t_game *game);
void	render_map(t_game *game);
void	move_player(t_game *game, int new_x);
void	key_hook(mlx_key_data_t keydata, void *param);
void	cleanup_game(t_game *game);
void	ft_error(const char *message);

#endif