/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xpm_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:17:54 by nali              #+#    #+#             */
/*   Updated: 2022/03/20 16:31:17 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_image(t_program **g)
{
	char		*enemy;
	static void	*img;
	int			pos[2];

	enemy = "./assets/enemy.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, enemy, &pos[0], &pos[1]);
	(*g)->enemy = img;
}

void	ft_skull_image(t_program **g)
{
	char		*skull;
	static void	*img;
	int			pos[2];

	skull = "./assets/skull.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, skull, &pos[0], &pos[1]);
	(*g)->skull = img;
}

void	ft_player_image(t_program **g)
{
	static void	*img;
	int			pos[2];
	char		*player;

	player = "./assets/plyr7.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->player = img;
}
