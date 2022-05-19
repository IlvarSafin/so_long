/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:01:15 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/21 13:01:19 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_close(t_game *game)
{
	del(game);
	write(1, "Window closed\n", 14);
	exit(0);
	return (0);
}

int	main(void)
{
	t_game	*game;
	int		fd;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	fd = open("map", O_RDWR);
	init(game);
	if (!ft_map(fd, game->map))
		return (0);
	if (!check(game->map, game))
		return (0);
	game->win = mlx_new_window(game->mlx,
			game->map->width * 32, game->map->hight * 32, "so long");
	out(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, enemy_walk, game);
	mlx_hook(game->win, 17, 1L << 0, game_close, game);
	mlx_loop(game->mlx);
}
