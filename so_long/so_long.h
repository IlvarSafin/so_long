/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:05:23 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 20:47:53 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_map {
	int		hight;
	int		width;
	int		player;
	int		coin;
	int		wall;
	char	**map;
}				t_map;

typedef struct s_img {
	void	*player_down1;
	void	*player_down2;
	void	*player_down3;
	void	*player_down4;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*wall;
	void	*terra;
	void	*food;
	void	*enemy;
	void	*exit;
	void	*exit2;
	void	*action;
}				t_img;

typedef struct s_game {
	void	*door;
	void	*player;
	void	*food;
	void	*mlx;
	void	*win;
	int		frame;
	int		enemyx;
	int		enemyy;
	int		enemyx2;
	int		enemyy2;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		score;
	int		steps;
	int		count;
	int		p;
	int		p2;
	int		ationpoint;
	t_map	*map;
	t_img	*img;
}				t_game;

void	ft_putnbr(int n);
char	*ft_itoa(int n);
void	init(t_game *game);
int		enemy_walk(t_game *game);
int		key_hook(int key, t_game *game);
void	init(t_game *game);
int		ft_map(int fd, t_map *game);
void	out(t_game *game);
void	ft_move_player(t_game *game, int y, int x, int frame);
int		check(t_map *game, t_game *g);
void	del(t_game *game);
void	ft_draw_tile_2(t_game *game, void *tile2, int y, int x);

#endif