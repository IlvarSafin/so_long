/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:54:02 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 20:57:24 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy1_walk(t_game *game)
{
	if (game->count == 4000)
	{
		ft_draw_tile_2(game, game->img->terra, game->enemyy, game->enemyx);
		game->map->map[game->enemyy][game->enemyx] = '0';
		game->count = 0;
		if (game->map->map[game->enemyy][game->enemyx - 1] == '1' && game->p)
			game->p = 0;
		if (game->map->map[game->enemyy][game->enemyx + 1] == '1' && !game->p)
			game->p = 1;
		if (game->p)
			game->enemyx--;
		else
			game->enemyx++;
		game->map->map[game->enemyy][game->enemyx] = 'v';
		ft_draw_tile_2(game, game->img->enemy, game->enemyy, game->enemyx);
	}
}

void	enemy2_walk(t_game *game)
{
	if (game->count == 2000)
	{
		ft_draw_tile_2(game, game->img->terra, game->enemyy2, game->enemyx2);
		game->map->map[game->enemyy2][game->enemyx2] = '0';
		if (game->map->map[game->enemyy2 - 1][game->enemyx2] == '1' && game->p2)
			game->p2 = 0;
		if (game->map->map[game->enemyy2 + 1][game->enemyx2] == '1'
			&& !game->p2)
			game->p2 = 1;
		if (game->p2)
			game->enemyy2--;
		else
			game->enemyy2++;
		game->map->map[game->enemyy2][game->enemyx2] = 'v';
		ft_draw_tile_2(game, game->img->enemy, game->enemyy2, game->enemyx2);
	}
}

int	enemy_walk(t_game *game)
{
	game->count++;
	if (game->enemyy == game->py && game->px == game->enemyx)
		exit(0);
	if (game->enemyy2 == game->py && game->px == game->enemyx2)
		exit(0);
	if (game->enemyx != -1)
		enemy1_walk(game);
	if (game->enemyx2 != -1)
		enemy2_walk(game);
	if (game->count == 4000)
		game->count = 0;
	if (game->count == 2000 && game->ationpoint == 1)
	{
		ft_draw_tile_2(game, game->img->terra, game->py, game->px);
		ft_draw_tile_2(game, game->img->action, game->py, game->px);
	}
	if (game->count == 3500 && game->ationpoint == 1)
	{
		ft_draw_tile_2(game, game->img->terra, game->py, game->px);
		ft_draw_tile_2(game, game->img->player_down1, game->py, game->px);
	}
	return (0);
}
