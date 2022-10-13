/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:41:42 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:15:01 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_program **game)
{
	mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
	ft_free_memory(game);
	exit(0);
}

int	ft_read_key(int keycode, t_program **game)
{
	// once game is over dont perform any action on key press
	//we include keycode !=53 because otherwise once the game is over
	// it doesn't close the window  on pressing esc
	if ((*game)->game_over == 1 && keycode != 53)
		return (1);
	if (keycode == 1)
		ft_move_vertical(game, 1); // s key
	if (keycode == 13)
		ft_move_vertical(game, -1);// w key
	if (keycode == 2)
		ft_move_horizontal(game, 1);// d key
	if (keycode == 0)
		ft_move_horizontal(game, -1);// a key
	if (keycode == 53) // esc key
		ft_close(game);
	return (0);
}

void	ft_free_memory(t_program **game)
{
	int		i;
	int		h;

	i = 0;
	h = (*game)->map_height;
	if ((*game)->map_data != NULL)
	{
		while (i <= h && h > 2)
		{
			free((*game)->map_data[i]);
			i++;
		}
		free((*game)->map_data);
	}
	free(*game);
}

int	main(int argc, char *argv[])
{
	t_program	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
		return (1);
	}
	game = malloc(sizeof(t_program));
	if (!game)
		return (1);
	// if map is invalid stop the program
	//memory is freed in the ft_get_map function
	if (!(ft_get_map(argv, &game)))
		return (0);
	game->game_over = 0;
	game->game_score = 0;
	game->steps = 0;
	game->danger = 0;
	ft_initialize_game(&game);
	//everytime a key is pressed ft_read_key function is called
	mlx_key_hook(game->win_ptr, ft_read_key, &game);
	// 17 is on_destroy event, which means ft_close is called when we press the close button
	mlx_hook(game->win_ptr, 17, 1L << 17, ft_close, &game);
	mlx_loop_hook(game->mlx_ptr, ft_animate, &game);
	// to initiate a loop  we need mlx_loop
	//this is an infinite loop which never returns
	//to stop the program it waits for esc key to be pressed or event 17
	mlx_loop(game->mlx_ptr);
	// we dont need to free memeory here as the loop never returns
	ft_free_memory(&game);
	return (0);
}
