/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nali <nali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:16:55 by nali              #+#    #+#             */
/*   Updated: 2022/03/21 09:03:42 by nali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_length(t_program **game)
{
	int	h;
	int	w;
	int	i;

	h = (*game)->map_height;
	w = (*game)->map_length;
	i = 0;
	while (i < h)
	{
		if (ft_strlen((*game)->map_data[i]) != w)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(t_program **game)
{
	if (ft_check_length(game) == 1)
		return (1);
	if (ft_check_walls(game) == 1)
		return (1);
	if (ft_check_player(game) == 1)
		return (1);
	if (ft_check_exit(game) == 1)
		return (1);
	if (ft_check_collectible(game) == 1)
		return (1);
	if (ft_check_invalid_elements(game) == 1)
		return (1);
	return (0);
}

char	*ft_trim_newline(char *str)
{
	char	*trimmed;
	int		l;

	l = ft_strlen(str);
	//here instead of l+ 1 we are using l beacuse we need to trim \n
	trimmed = (char *)malloc(l * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str, l);
	free(str);
	return (trimmed);
}

void	ft_read_from_file(int fd, t_program **game)
{
	int		i;
	int		h;
	char	*str;

	i = 0;
	h = (*game)->map_height;
	(*game)->map_data = (char **)malloc((h + 1) * sizeof(char *));
	str = get_next_line(fd);
	while (str != NULL)
	{
		//while reading the map, the program reads the newline also
		//so if newline present trim the newline
		if (ft_strchr(str, '\n') != NULL)
			str = ft_trim_newline(str);
		(*game)->map_data[i] = str;
		i++;
		str = get_next_line(fd);
	}
	(*game)->map_data[i] = NULL;
	(*game)->map_length = ft_strlen((*game)->map_data[0]);
}

int	ft_get_map(char **argv, t_program **game)
{
	int	fd;
	//checks the .ber extension
	if (ft_check_file_ext(argv[1]) == 0)
	{
		ft_putstr_fd("Map should be of .ber extension.\n", 1);
		return (0);
	}
	(*game)->map_height = ft_get_map_height(argv[1]);
	if ((*game)->map_height <= 2)
	{
		ft_putstr_fd("Invalid Map - Map should have atleast 3 rows.\n", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	//reads the ap into a 2d array
	ft_read_from_file(fd, game);
	close(fd);
	//do all checks on the map format
	if (ft_check_map(game) == 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_free_memory(game);
		return (0);
	}
	return (1);
}
