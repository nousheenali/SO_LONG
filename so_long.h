/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:41:53 by nali              #+#    #+#             */
/*   Updated: 2022/03/20 17:07:30 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	5
# endif

# ifndef BONUS
#  define BONUS	0
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>

# define TILE_WIDTH 80
# define PLYR1 "./assets/plyr1.xpm"
# define PLYR2 "./assets/plyr2.xpm"
# define PLYR3 "./assets/plyr3.xpm"
# define PLYR4 "./assets/plyr4.xpm"
# define PLYR5 "./assets/plyr5.xpm"
# define PLYR6 "./assets/plyr6.xpm"
# define PLYR7 "./assets/plyr7.xpm"
# define PLYR8 "./assets/plyr8.xpm"
# define PLYR9 "./assets/plyr9.xpm"
# define PLYR10 "./assets/plyr10.xpm"
# define PLYR11 "./assets/plyr11.xpm"

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map_data;
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
	int		exit_pos_x;
	int		exit_pos_y;
	void	*wall;
	void	*exit;
	void	*openexit;
	void	*player;
	void	*players[11];
	void	*enemy;
	void	*skull;
	void	*bg;
	void	*coin;
	int		enemy_count;
	int		enemy_pos_x;
	int		enemy_pos_y;
	int		game_score;
	int		max_score;	
	int		game_over;	
	int		steps;
	int		danger;
}	t_program;

//so_long.c
int		ft_read_keys(int keycode, t_program *param);
void	ft_free_memory(t_program **game);
// ft_map_functions
int		ft_get_map(char **argv, t_program **game);
//get_next_line
char	*get_next_line(int fd);
//get_next_line_utils
int		ft_findlen(const char *s);
char	*str_concat(char *s1, const char *s2);
//ft_map_checks
int		ft_check_walls(t_program **game);
int		ft_check_player(t_program **game);
int		ft_check_collectible(t_program **game);
int		ft_check_exit(t_program **game);
int		ft_check_invalid_elements(t_program **game);
//ft_check_file_ext
int		ft_check_file_ext(char *path);
//ft_so_long_utils
int		ft_get_map_height(char *path);
void	ft_free_string(char *steps_str, char *tstr);
void	ft_print_game_over(t_program **g, char *str);
//ft_initialize_game
void	ft_initialize_game(t_program **game);
void	ft_display(t_program **game);
void	ft_print_on_window(t_program **g, void *p, int x, int y);
//ft_convert_xpm
void	ft_wall_image(t_program **g);
void	ft_coin_image(t_program **g);
void	ft_exit_image(t_program **g);
void	ft_bg_image(t_program **g);
void	ft_convert_xpm_to_img(t_program **game);
// ft_convert_xpm_2.c
void	ft_player_image(t_program **g);
void	ft_enemy_image(t_program **g);
void	ft_skull_image(t_program **g);
//ft_animate
void	ft_player_images_animate(t_program **g);
void	ft_player_images_animate_2(t_program **g);
int		ft_animate(t_program **game);
void	ft_print_steps(t_program **g, int steps);
//ft_move_player.c 
void	ft_move_vertical(t_program **game, int dir);
void	ft_move_horizontal(t_program **game, int dir);
//ft_put_enemy.c
void	ft_display_enemy(t_program **g);
//ft_move_enemy
int		ft_move_enemy(t_program **game);

#endif