/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:23:16 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:24 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Colors
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

// Window settings
# define TITLE "so_long"

// Game elements
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

// Key codes for MLX42
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define KEY_ESC MLX_KEY_ESCAPE

// RETURN CODE
# define SUCCESS 0
# define FAIL 1

// Tile size in pixels
# define TILE_SIZE 32

typedef struct s_floodfill
{
	int			x;
	int			y;
	int			*collec;
	int			*exit;
}				t_floodfill;

typedef enum e_direction
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
}				t_direction;

// Game structure
typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_inwall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_collectible;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player_up;
	mlx_image_t	*img_player_down;
	mlx_image_t	*img_player_left;
	mlx_image_t	*img_player_right;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	int			exit_open;
	t_direction	player_dir;
}				t_game;

// Map utils
void			free_map_on_error(char **map, int lines);
void			free_map(char **map);
int				get_rows(char **map);
int				get_columns(char **map);
int				characters_to_check(char *line, const char *chars);

// Map validations
int				has_valid_path(char **map);
int				has_valid_chars(char **map);
int				has_valid_start_exit_collec(char **map);
int				has_valid_walls(char **map);

// Main map functions
int				validate_map(char **map);
char			**parse_map(char *map_path);

// Cleanup functions
int				free_and_exit(char **map);
void			cleanup_images(t_game *game);
int 			free_and_exit_with_cleanup(t_game *game);

int				init_game(t_game *game);
void			render_map(t_game *game);
void 			free_map_mlx(t_game *game);
void			key_hook(mlx_key_data_t keydata, void *param);
void			move_player(t_game *game, int dx, int dy);
void			update_player_position(t_game *game);
void			exit_status(t_game *game);
int 			count_collectibles(t_game *game);
void 			victory(t_game *game);
void 			update_collectibles(t_game *game, int new_x, int new_y);

#endif