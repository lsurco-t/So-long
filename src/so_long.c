/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 23:52:07 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf(RED "Usage: so_long ./maps/xxx.ber\n" RESET);
		return (FAIL);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.map = parse_map(argv[1]);
	if (!game.map || !game.map[0])
		return (failed_parse_map());
	if (validate_map(game.map) == FAIL)
		return (free_and_exit(game.map));
	count_collectibles(&game);
	default_player_position(&game);
	if (init_game(&game) == FAIL)
		return (free_and_exit_with_cleanup(&game));
	render_map(&game);
	render_player(&game, game.player_x, game.player_y);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	free_map_mlx(&game);
	return (SUCCESS);
}
