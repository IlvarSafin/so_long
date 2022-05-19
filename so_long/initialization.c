/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:58:25 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/18 20:59:05 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img2(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img->player_down4 = mlx_xpm_file_to_image(game->mlx,
			"./person/down4.xpm", &img_width, &img_height);
	game->img->player_left = mlx_xpm_file_to_image(game->mlx,
			"./person/left.xpm", &img_width, &img_height);
	game->img->player_right = mlx_xpm_file_to_image(game->mlx,
			"./person/right.xpm", &img_width, &img_height);
	game->img->exit = mlx_xpm_file_to_image(game->mlx,
			"./exit.xpm", &img_width, &img_height);
	game->img->exit2 = mlx_xpm_file_to_image(game->mlx,
			"./exit1.xpm", &img_width, &img_height);
	game->img->enemy = mlx_xpm_file_to_image(game->mlx,
			"./enemy.xpm", &img_width, &img_height);
	game->img->action = mlx_xpm_file_to_image(game->mlx,
			"./person/action.xpm", &img_width, &img_height);
}

void	init_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img->terra = mlx_xpm_file_to_image(game->mlx,
			"./terra.xpm", &img_width, &img_height);
	game->img->food = mlx_xpm_file_to_image(game->mlx,
			"./food.xpm", &img_width, &img_height);
	game->img->wall = mlx_xpm_file_to_image(game->mlx,
			"./wall.xpm", &img_width, &img_height);
	game->img->player_up = mlx_xpm_file_to_image(game->mlx,
			"./person/up1.xpm", &img_width, &img_height);
	game->img->player_down1 = mlx_xpm_file_to_image(game->mlx,
			"./person/down1.xpm", &img_width, &img_height);
	game->img->player_down2 = mlx_xpm_file_to_image(game->mlx,
			"./person/down2.xpm", &img_width, &img_height);
	game->img->player_down3 = mlx_xpm_file_to_image(game->mlx,
			"./person/down3.xpm", &img_width, &img_height);
	init_img2(game);
}

void	init(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map) * 1);
	game->img = (t_img *)malloc(sizeof(t_img) * 1);
	game->mlx = mlx_init();
	game->map->coin = 0;
	game->score = 0;
	game->steps = 0;
	game->frame = 0;
	game->count = 0;
	game->enemyx = -1;
	game->enemyx2 = -1;
	init_img(game);
}
