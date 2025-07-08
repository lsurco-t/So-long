/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/08 13:30:43 by lsurco-t         ###   ########.fr       */
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
	{
		ft_printf("Error\nFailed to read map file\n");
		return (FAIL);
	}
	if (validate_map(game.map) == FAIL)
		free_and_exit(game.map);
	init_game(&game);
	render_map(&game);
	return (0);
}
