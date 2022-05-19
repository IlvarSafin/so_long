/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:48:28 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 21:06:14 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move1(t_game *game, int frame)
{
	if (frame == 1)
		ft_draw_tile_2(game, game->img->player_down1, game->py, game->px);
	if (frame == 2)
		ft_draw_tile_2(game, game->img->player_down2, game->py, game->px);
	if (frame == 3)
		ft_draw_tile_2(game, game->img->player_down3, game->py, game->px);
	if (frame == 4)
		ft_draw_tile_2(game, game->img->player_down4, game->py, game->px);
	if (frame == 10)
		ft_draw_tile_2(game, game->img->player_up, game->py, game->px);
	if (frame == 11)
		ft_draw_tile_2(game, game->img->player_left, game->py, game->px);
	if (frame == 12)
		ft_draw_tile_2(game, game->img->player_right, game->py, game->px);
}

void	defif(t_game *game)
{
	del(game);
	write(1, "Window closed\n", 14);
	exit (0);
}

void	screen_steps(t_game *game)
{
	char	*steps;

	mlx_put_image_to_window(game->mlx, game->win,
		game->img->wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img->wall, 32, 0);
	steps = ft_itoa(game->steps);
	if (steps)
		mlx_string_put(game->mlx, game->win, 10, 10, -1, steps);
	if (steps)
		free(steps);
}

void	print(t_game *game)
{
	write(1, "Steps: ", 7);
	game->steps++;
	ft_putnbr(game->steps);
	write(1, "\n", 2);
	screen_steps(game);
}

void	ft_move_player(t_game *game, int y, int x, int frame)
{
	if (game->map->map[game->py - y][game->px - x] == '1')
		return ;
	if (game->map->map[game->py - y][game->px - x] == 'C')
	{
		game->map->map[game->py - y][game->px - x] = '0';
		game->score++;
	}
	if (game->score == game->map->coin)
		ft_draw_tile_2(game, game->img->exit2, game->ey, game->ex);
	if (game->map->map[game->py - y][game->px - x] == 'E')
	{
		if (game->score == game->map->coin)
			defif(game);
		else
			return ;
	}
	if (game->map->map[game->py - y][game->px - x] == 'v')
		defif(game);
	ft_draw_tile_2(game, game->img->terra, game->py, game->px);
	game->px -= x;
	game->py -= y;
	move1(game, frame);
	print(game);
}
