/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:42:50 by nali              #+#    #+#             */
/*   Updated: 2022/02/18 22:42:50 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_new_pos_2(int x, int y, t_program **g)
{
	if ((*g)->map_data[y][x] == 'E')
	{
		if ((*g)->max_score == (*g)->game_score)
		{
			(*g)->game_over = 1;
			return (1);
		}
		else
			return (0);
	}
	else if ((*g)->map_data[y][x] == 'X')
	{		
		(*g)->game_over = 1;
		(*g)->danger = 1;
		return (1);
	}
	return (1);
}

int	ft_check_new_pos(int x, int y, t_program **g)
{
	int	val;

	if ((*g)->map_data[y][x] == '0')
		return (1);
	else if ((*g)->map_data[y][x] == '1')
		return (0);
	else if ((*g)->map_data[y][x] == 'C')
	{
		ft_print_on_window(g, (*g)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
		(*g)->map_data[y][x] = '0';
		(*g)->game_score++;
		return (1);
	}
	else if ((*g)->map_data[y][x] == 'E' || (*g)->map_data[y][x] == 'X')
	{
		val = ft_check_new_pos_2(x, y, g);
		return (val);
	}
	return (1);
}

void	ft_game_over(t_program **game, int x, int y)
{
	int	px;
	int	py;

	ft_print_on_window(game, (*game)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
	px = x * TILE_WIDTH;
	py = y * TILE_WIDTH;
	if ((*game)->danger == 1)
	{
		// when game is over due to player touching the enemy
		ft_print_on_window(game, (*game)->skull, px, py);
		ft_print_game_over(game, "Game Over!");
	}
	else
	{
		//when game is over when player collects all coins
		ft_print_on_window(game, (*game)->openexit, px, py);
		(*game)->map_data[y][x] = 'E';
		ft_print_game_over(game, "You Win!");
	}
}

void	ft_move_vertical(t_program **game, int dir)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = (*game)->player_position_x;
	y = (*game)->player_position_y;
	if (ft_check_new_pos(x, y + dir, game))
	{
		ft_print_on_window(game, (*game)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
		(*game)->map_data[y][x] = '0';
		y = y + dir;
		(*game)->player_position_y = y;
		(*game)->map_data[y][x] = 'P';
		px = x * TILE_WIDTH;
		py = y * TILE_WIDTH;
		ft_print_on_window(game, (*game)->player, px, py);
		(*game)->steps++;
		ft_print_steps(game, (*game)->steps);
	}
	if ((*game)->game_over == 1)
		ft_game_over(game, x, y);
}

void	ft_move_horizontal(t_program **game, int dir)
{
	int	x;
	int	y;
	int	px;
	int	py;

	x = (*game)->player_position_x;
	y = (*game)->player_position_y;
	if (ft_check_new_pos(x + dir, y, game))
	{
		//when it is a valid move we place a background on the player hiding him
		ft_print_on_window(game, (*game)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
		(*game)->map_data[y][x] = '0';
		x = x + dir;
		(*game)->map_data[y][x] = 'P';
		(*game)->player_position_x = x;
		px = x * TILE_WIDTH;
		py = y * TILE_WIDTH;
		ft_print_on_window(game, (*game)->player, px, py);
		(*game)->steps++;
		ft_print_steps(game, (*game)->steps);
	}
	if ((*game)->game_over == 1)
		ft_game_over(game, x, y);
}
