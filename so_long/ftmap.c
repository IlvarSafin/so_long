/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:51:00 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/16 19:24:58 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map1(int fd, int *max, int *c)
{
	int		i;
	char	*l;

	while (1)
	{
		i = 0;
		l = get_next_line(fd);
		if (!l)
			break ;
		while (l[i])
			i++;
		if (*max == -1)
			*max = i;
		if (i != *max)
			exit (0);
		free(l);
		*c = *c + 1;
	}
}

int	ft_map(int fd, t_map *game)
{
	int		c;
	int		i;
	int		max;

	c = 0;
	max = -1;
	i = 0;
	map1(fd, &max, &c);
	game->width = max;
	game->map = (char **)malloc(sizeof(char *) * (c + 1));
	game->map[c] = 0;
	game->hight = c;
	close(fd);
	fd = open("map", O_RDWR);
	while (c-- > 0)
		game->map[i++] = get_next_line(fd);
	return (1);
}
