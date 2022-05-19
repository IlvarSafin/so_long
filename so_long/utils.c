/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:23:57 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 17:06:50 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile_2(t_game *game, void *tile2, int y, int x)
{
	y = y * 32;
	x = x * 32;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img->terra, x, y);
	mlx_put_image_to_window(game->mlx, game->win, tile2, x, y);
}

void	del(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->map->hight)
		free(game->map->map[i++]);
	free(game->map);
	free(game->img);
	free(game);
}
