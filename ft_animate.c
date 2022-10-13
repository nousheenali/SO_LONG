/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:37:12 by nali              #+#    #+#             */
/*   Updated: 2022/02/21 09:37:12 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_images_animate(t_program **g)
{
	static void	*img;
	int			pos[2];
	char		*player;

	player = "./assets/plyr1.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[0] = img;
	player = "./assets/plyr2.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[1] = img;
	player = "./assets/plyr3.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[2] = img;
	player = "./assets/plyr4.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[3] = img;
	player = "./assets/plyr5.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[4] = img;
}

void	ft_player_images_animate_2(t_program **g)
{
	static void	*img;
	int			pos[2];
	char		*player;

	player = "./assets/plyr6.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[5] = img;
	player = "./assets/plyr7.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[6] = img;
	player = "./assets/plyr8.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[7] = img;
	player = "./assets/plyr9.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[8] = img;
	player = "./assets/plyr10.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[9] = img;
	player = "./assets/plyr11.xpm";
	img = mlx_xpm_file_to_image((*g)->mlx_ptr, player, &pos[0], &pos[1]);
	(*g)->players[10] = img;
}

// keeps looping between the 10 player images to create an illusion of movement
void	ft_animate_display(t_program **g, int i, int *frames)
{
	int	x;
	int	y;

	x = (*g)->player_position_x;
	y = (*g)->player_position_y;
	ft_print_on_window(g, (*g)->bg, x * TILE_WIDTH, y * TILE_WIDTH);
	ft_print_on_window(g, (*g)->players[i], x * 80, y * 80);
	*frames = 0;
}

int	ft_animate(t_program **g)
{
	static int	i;
	static int	frames;
	static int	count;

	if (BONUS == 1)
	{
		// we have separate count for enemy and player evaluation coz to 
		// prevent the frames from getting stuck when the player and enemy touch each other
		if (count == 8000)
		{
			ft_move_enemy(g);
			count = 0;
		}
		count++;
		while (i <= 10 && (*g)->game_over != 1)
		{
			if (frames == 10000)
				ft_animate_display(g, i, &frames);
			i++;
			frames++;
		}
		i = 0;
	}
	return (0);
}

void	ft_print_steps(t_program **g, int steps)
{
	char	*steps_str;
	char	str[8];
	char	*tstr;
	int		i;

	ft_strlcpy(str, "Moves: ", 8);
	if (BONUS == 0)
	{
		ft_putstr_fd(str, 1);
		ft_putnbr_fd(steps, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		steps_str = ft_itoa(steps);
		tstr = ft_strjoin(str, steps_str);
		i = 0;
		while (i < (*g)->map_length)
		{
			ft_print_on_window(g, (*g)->wall, i * TILE_WIDTH, 0);
			i++;
		}
		mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 10, 40, 0xFE6500, tstr);
		ft_free_string(steps_str, tstr);
	}
}
