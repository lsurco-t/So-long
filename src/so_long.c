/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:21:40 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/07 15:36:12 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	struct t_game  *game;

	if (argc == 2)
	{	
		validate_map(game);
		render_map(game);
		cleanup_game(game);
	}
	else
	{
		ft_printf(RED "Usage: so_long ./maps/xxx.ber" RESET);
		return (1);
	}
	return (0);
}