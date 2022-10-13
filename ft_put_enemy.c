/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:03:44 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:11:49 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_enemy(t_program **game, int pos_x, int pos_y)
{
	int	x;
	int	y;

	x = pos_x * TILE_WIDTH;
	y = pos_y * TILE_WIDTH;
	(*game)->enemy_pos_x = pos_x;
	(*game)->enemy_pos_y = pos_y;
	ft_print_on_window(game, (*game)->enemy, x, y);
}

//here we display only the first enemy
//if more enemy present the program will simply replace it with 0(background)
void	ft_display_enemy(t_program **g)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	while (i < (*g)->map_height)
	{
		while (j < (*g)->map_length)
		{
			if ((*g)->map_data[i][j] == 'X')
			{
				if (num == 0)
					ft_print_enemy(g, j, i);
				else
					(*g)->map_data[i][j] = '0';
				num++;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
