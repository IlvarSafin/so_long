/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:59:22 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 21:06:16 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	long long	nb;
	char		a;

	nb = (long long)n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	a = (char)(nb % 10 + 48);
	write(1, &a, 1);
}

void	one(t_game *game)
{
	if (game->frame++ == 0)
		ft_move_player(game, -1, 0, 2);
	else if (game->frame++ == 1)
		ft_move_player(game, -1, 0, 3);
	else if (game->frame++ == 2)
		ft_move_player(game, -1, 0, 4);
	else
	{
		game->frame = 0;
		ft_move_player(game, -1, 0, 1);
	}
}

int	key_hook(int key, t_game *game)
{
	game->ationpoint = key;
	if (key == 13)
		ft_move_player(game, 1, 0, 10);
	if (key == 1)
		one(game);
	if (key == 0)
		ft_move_player(game, 0, 1, 11);
	if (key == 2)
		ft_move_player(game, 0, -1, 12);
	if (key == 53)
	{
		del(game);
		write(1, "Window closed\n", 14);
		exit(0);
	}
	return (0);
}
