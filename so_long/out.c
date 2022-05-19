/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:48:58 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 17:09:46 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	out1(t_game *game, char point, int *x, int y)
{
	if (point == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->wall, *x, y);
		*x = *x + 32;
	}
	if (point == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->terra, *x, y);
		*x = *x + 32;
	}
	if (point == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->terra, *x, y);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img->player_down1, *x, y);
		*x = *x + 32;
	}
	if (point == 'v')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->terra, *x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->enemy, *x, y);
		*x = *x + 32;
	}
}

void	out2(t_game *game, char point, int *x, int y)
{
	if (point == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->terra, *x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->food, *x, y);
		*x = *x + 32;
	}
	if (point == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->terra, *x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img->exit, *x, y);
		*x = *x + 32;
	}
}

void	out(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	while (game->map->map[i])
	{
		x = 0;
		j = 0;
		while (game->map->map[i][j])
		{
			out1(game, game->map->map[i][j], &x, y);
			out2(game, game->map->map[i][j], &x, y);
			++j;
		}
		y += 32;
		++i;
	}
}
