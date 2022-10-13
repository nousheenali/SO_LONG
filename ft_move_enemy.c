/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:28:56 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:55:06 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_new_pos_bonus(int x, int y, t_program **g, int *flag)
{
	if ((*g)->map_data[y][x] == '0')
		return (1);
	else if ((*g)->map_data[y][x] == 'P')
	{
		(*g)->game_over = 1;
		(*g)->danger = 1;
		return (1);
	}
	else
	{
		// flag is used so that the player doesn't get stuck in one direction
		(*flag) += 1;
		if ((*flag) >= 4)
			*flag = 0;
		return (0);
	}
	return (1);
}

void	ft_print_enemy_new_pos(int x, int y, t_program **game)
{
	(*game)->enemy_pos_x = x;
	(*game)->enemy_pos_y = y;
	(*game)->map_data[y][x] = 'X';
	if ((*game)->danger != 1)
		ft_print_on_window(game, (*game)->enemy, x * 80, y * 80);
}

void	ft_print_enemy_old_pos(int x, int y, t_program **game)
{
	int	i;
	int	j;

	i = (*game)->player_position_x;
	j = (*game)->player_position_y;
	if ((*game)->danger == 1)
	{
		ft_print_on_window(game, (*game)->bg, i * TILE_WIDTH, j * TILE_WIDTH);
		ft_print_on_window(game, (*game)->skull, i * 80, j * 80);
		ft_print_on_window(game, (*game)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
		ft_print_game_over(game, "Game Over!");
	}
	else
	{
		(*game)->map_data[y][x] = '0';
		ft_print_on_window(game, (*game)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
	}
}

// we are using a flag counter here so that the enemy doesn't get stuck
void	ft_move(int x, int y, t_program **game, int *flag)
{
	if (*flag == 0 && ft_check_new_pos_bonus(x + 1, y, game, flag))
	{
		ft_print_enemy_old_pos(x, y, game);
		ft_print_enemy_new_pos(x + 1, y, game);
	}
	else if (*flag == 1 && ft_check_new_pos_bonus(x, y + 1, game, flag))
	{
		ft_print_enemy_old_pos(x, y, game);
		ft_print_enemy_new_pos(x, y + 1, game);
	}
	else if (*flag == 2 && ft_check_new_pos_bonus(x - 1, y, game, flag))
	{
		ft_print_enemy_old_pos(x, y, game);
		ft_print_enemy_new_pos(x - 1, y, game);
	}
	else if (*flag == 3 && ft_check_new_pos_bonus(x, y - 1, game, flag))
	{
		ft_print_enemy_old_pos(x, y, game);
		ft_print_enemy_new_pos(x, y - 1, game);
	}
}

int	ft_move_enemy(t_program **game)
{
	static int	flag;

	// to prvent segmentation fault ft_move should be called only when there is an enemy
	if ((*game)->enemy_count > 0)
		ft_move((*game)->enemy_pos_x, (*game)->enemy_pos_y, game, &flag);
	return (0);
}
