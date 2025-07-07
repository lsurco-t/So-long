/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 21:01:03 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game  game;

	if (argc != 2)
	{
		ft_printf(RED "Usage: so_long ./maps/xxx.ber\n" RESET);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	game.map = parse_map(argv[1]);
	if(!game.map)
	{
		ft_printf("Error\nFailed to read map file\n");
        return (1);
	}
	if (validate_map(game.map) == FAIL)
    {
        free_map(game.map);
        return (1);
    }
	init_game(&game);
    render_map(&game);
	return (0);
}
