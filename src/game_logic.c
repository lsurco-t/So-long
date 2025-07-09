/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsurco-t <lsurco-t@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:52:18 by lsurco-t          #+#    #+#             */
/*   Updated: 2025/07/09 16:34:09 by lsurco-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_status(t_game *game)
{
	if (game->collectibles == 0)
	{
		game->exit_open = 1;
		return (SUCCESS);
	}
	else
	{
		game->exit_open = 0;
		return (FAIL);
	}
}