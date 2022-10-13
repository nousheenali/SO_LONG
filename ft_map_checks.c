/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:43:06 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:07:11 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks if the map has its border as 1's
int	ft_check_walls(t_program **game)
{
	int	h;
	int	w;
	int	i;

	h = (*game)->map_height;
	w = (*game)->map_length;
	i = 0;
	while (i < w)
	{
		if ((*game)->map_data[0][i] == '1' & (*game)->map_data[h - 1][i] == '1')
			i++;
		else
			return (1);
	}
	i = 0;
	while (i < h)
	{
		if ((*game)->map_data[i][0] == '1' & (*game)->map_data[i][w - 1] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

// checks if a player is present. if yes stores his location
int	ft_check_player(t_program **game)
{
	int			i;
	int			j;
	static int	count;

	i = 0;
	j = 0;
	while (i < (*game)->map_height)
	{
		while (j < (*game)->map_length)
		{
			if ((*game)->map_data[i][j] == 'P')
			{
				(*game)->player_position_x = j;
				(*game)->player_position_y = i;
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (0);
	else
		return (1);
}

//checks if collectible is present. If yes, keep a count.
//this count will be the max score
int	ft_check_collectible(t_program **game)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (i < (*game)->map_height)
	{
		j = 0;
		while (j < (*game)->map_length)
		{
			if ((*game)->map_data[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	(*game)->max_score = count;
	if (count > 0)
		return (0);
	else
		return (1);
}

//checks if exit is present
int	ft_check_exit(t_program **game)
{
	static int	i;
	int			j;

	while (i < (*game)->map_height)
	{
		j = 0;
		while (j < (*game)->map_length)
		{
			if ((*game)->map_data[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// checks if an invalid element is present
//if bonus=1 then X is not t=reated as invalid element
//if bonus = 1 we keep a count of the enemies
int	ft_check_invalid_elements(t_program **game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	(*game)->enemy_count = 0;
	while (i < (*game)->map_height)
	{
		while (j < (*game)->map_length)
		{
			c = (*game)->map_data[i][j];
			if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'))
			{
				if (c == 'X' && BONUS == 1)
					(*game)->enemy_count++;
				else
					return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
