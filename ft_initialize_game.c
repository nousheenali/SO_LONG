/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:42:12 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:48:55 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_on_window(t_program **g, void *p, int x, int y)
{
	void	*m;
	void	*w;

	m = (*g)->mlx_ptr;
	w = (*g)->win_ptr;
	mlx_put_image_to_window(m, w, p, x, y);
}

void	ft_put_tile(char val, int *pos, t_program **g)
{
	//before placing any element we place the background first
	//else collectibles, exit and player will have black background
	ft_print_on_window(g, (*g)->bg, pos[0], pos[1]);
	if (val == '1')
		ft_print_on_window(g, (*g)->wall, pos[0], pos[1]);
	if (val == 'C')
		ft_print_on_window(g, (*g)->coin, pos[0], pos[1]);
	if (val == 'E')
		ft_print_on_window(g, (*g)->exit, pos[0], pos[1]);
}

// goes through each element one by one and dsiplays the corresonding image
void	ft_display(t_program **game)
{
	static int	w;
	static int	h;
	static int	pos[2];
	char		val;

	while (h < (*game)->map_height)
	{
		w = 0;
		pos[0] = 0;
		while (w < (*game)->map_length)
		{
			val = (*game)->map_data[h][w];
			ft_put_tile(val, pos, game);
			pos[0] += TILE_WIDTH;
			w++;
		}
		pos[1] += TILE_WIDTH;
		h++;
	}
}

// this function displyas the screen separately
//display the player separately
//displays enemy if bonus = 1
//if bonus = 0 the program will not reach this function as map will give an error
//so we dont need a check while displaying enemy
void	ft_initialize_game(t_program **game)
{
	int	ww;
	int	wh;
	int	x;
	int	y;

	ww = ((*game)->map_length) * TILE_WIDTH;
	wh = ((*game)->map_height + 1) * TILE_WIDTH;
	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr, ww, wh, "Game!");
	if (!((*game)->mlx_ptr && (*game)->win_ptr))
		return ;
	//converts the .xpm to image
	ft_convert_xpm_to_img(game);
	ft_display(game);
	//we dispaly player & enemy separately coz we will be changing its position
	x = (*game)->player_position_x * TILE_WIDTH;
	y = (*game)->player_position_y * TILE_WIDTH;
	ft_print_on_window(game, (*game)->player, x, y);
	ft_display_enemy(game);
}
