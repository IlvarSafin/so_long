/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:52:58 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 17:09:56 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check1(t_game *game, int *p, int i, int j)
{
	if ((i == 0 || i + 1 == game->map->hight)
		&& game->map->map[i][j] != '1')
	{
		write(1, "Are you serious?", 16);
		exit(0);
	}
	if ((j == 0 && game->map->map[i][j] != '1')
		|| (j + 1 == game->map->width && game->map->map[i][j] != '1'))
	{
		write(1, "Are you serious?", 16);
		exit (0);
	}
	if (game->map->map[i][j] == 'P')
	{
		p[0]++;
		game->py = i;
		game->px = j;
	}
	if (game->map->map[i][j] == 'C')
	{
		p[1] = 1;
		game->map->coin++;
	}
}

void	check2(t_game *game, int *p, int i, int j)
{
	if (game->map->map[i][j] == 'E')
	{
		p[2]++;
		game->ex = j;
		game->ey = i;
	}
	if (game->map->map[i][j] == 'v')
	{
		p[3]++;
		if (p[3] > 1)
		{
			game->enemyx2 = j;
			game->enemyy2 = i;
		}
		else
		{
			game->enemyx = j;
			game->enemyy = i;
		}
	}
}

void	hmm(int *p)
{
	if (p[0] != 1 || p[1] < 1 || p[2] < 1)
	{
		write(1, "hmm...not all", 13);
		exit(0);
	}
}

void	check3(char point)
{
	if (point != 'P' && point != 'E' && point != '1'
		&& point != 'C' && point != '0' && point != 'v')
	{
		write(1, "over many WTF?!", 15);
		exit(0);
	}
}

int	check(t_map *game, t_game *g)
{
	int	i;
	int	j;
	int	p[4];

	i = 0;
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check1(g, p, i, j);
			check2(g, p, i, j);
			check3(game->map[i][j]);
			++j;
		}
		++i;
	}
	hmm(p);
	return (1);
}
