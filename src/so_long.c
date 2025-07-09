/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 17:34:26 by lsurco-t         ###   ########.fr       */
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
	game.player_dir = DIR_DOWN;
	game.map = parse_map(argv[1]);
	if (!game.map || !game.map[0])
	{
		ft_printf("Error\nFailed to read map file\n");
		return (FAIL);
	}
	if (validate_map(game.map) == FAIL)
		return (free_and_exit(game.map));
	count_collectibles(&game);
	ft_printf(BLUE "Collectibles: %d\n" RESET, game.collectibles);
	update_player_position(&game);
	if (init_game(&game) == FAIL)
		return (free_and_exit_with_cleanup(&game));
	render_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	free_map_mlx(&game);
	return (SUCCESS);
}
