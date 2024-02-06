/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:43:02 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/04 15:06:27 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libfth/libft.h"

int	ft_rectangle(char **map, int row, int cols)
{
	int	j;

	j = 0;
	while (j < row)
	{
		if (map[0][j] != '1' || map[cols - 1][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (j < cols)
	{
		if (map[j][0] != '1' || map[j][row - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_row_length(char **map, int row, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (ft_strlen(map[i]) != row)
			return (1);
		i++;
	}
	return (0);
}

int	ft_charcter_check(char *str, t_map *map_stat, int size)
{
	int	i;

	i = 0;
	while (i < size -1)
	{
		if (str[i] == 'P')
			map_stat->player++;
		else if (str[i] == 'E')
			map_stat->exit++;
		else if (str[i] == 'C')
			map_stat->coin++;
		else if (str[i] != '0' && str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_counter(char **map, t_map *map_stat, int size)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		if (ft_charcter_check(map[i], map_stat, size))
			return (1);
		i++;
	}
	return (ft_check_error(map_stat));
}

t_map	ft_check(char **map)
{
	t_map	map_stat;

	map_stat.coin = 0;
	map_stat.player = 0;
	map_stat.exit = 0;
	map_stat.flag = 0;
	map_stat.pcoin = 0;
	map_stat.x = ft_strlen(map[0]);
	map_stat.y = ft_colm_counter(map);
	map_stat.stap = 0;
	if (ft_row_length(map, map_stat.x, map_stat.y))
		map_stat.flag = -1;
	if (ft_rectangle(map, map_stat.x, map_stat.y))
		map_stat.flag = -1;
	if (ft_counter(map, &map_stat, map_stat.x))
		map_stat.flag = -1;
	return (map_stat);
}
