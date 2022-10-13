/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:54 by nali              #+#    #+#             */
/*   Updated: 2022/03/16 11:39:14 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_image(t_program **g)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = "./assets/wall.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, wall, &pos[0], &pos[1]);
	(*g)->wall = img;
}

void	ft_coin_image(t_program **g)
{
	char		*coin;
	static void	*img;
	int			pos[2];

	coin = "./assets/coin.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, coin, &pos[0], &pos[1]);
	(*g)->coin = img;
}

void	ft_exit_image(t_program **g)
{
	char		*exit;
	char		*openexit;
	static void	*img;
	static void	*img2;
	int			pos[2];

	exit = "./assets/closeddoor.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, exit, &pos[0], &pos[1]);
	(*g)->exit = img;
	openexit = "./assets/opendoor.xpm";
	img2 = mlx_xpm_file_to_image((*g)->mlx_ptr, openexit, &pos[0], &pos[1]);
	(*g)->openexit = img2;
}

void	ft_bg_image(t_program **g)
{
	char		*bg;
	static void	*img;
	int			pos[2];

	bg = "./assets/bg.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, bg, &pos[0], &pos[1]);
	(*g)->bg = img;
}

void	ft_convert_xpm_to_img(t_program **game)
{
	ft_wall_image(game);
	ft_coin_image(game);
	ft_exit_image(game);
	ft_bg_image(game);
	ft_player_image(game);
	ft_player_images_animate(game);
	ft_player_images_animate_2(game);
	ft_enemy_image(game);
	ft_skull_image(game);
}
