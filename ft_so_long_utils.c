/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:27:21 by nali              #+#    #+#             */
/*   Updated: 2022/03/20 16:34:46 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_map_height(char *path)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	ft_free_string(char *steps_str, char *tstr)
{
	free(steps_str);
	free(tstr);
}

void	ft_print_game_over(t_program **g, char *str)
{
	void	*m;
	void	*w;
	int		y;
	int		x;

	y = (*g)->map_height;
	x = (*g)->map_length;
	m = (*g)->mlx_ptr;
	w = (*g)->win_ptr;
	mlx_string_put(m, w, (x / 2) * 80, (y * 80) + 40, 0xFE6500, str);
}
