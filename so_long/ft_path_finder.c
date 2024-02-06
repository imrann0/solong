/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:43:36 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:22 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libfth/libft.h"

char	**ft_map_copy(char **map)
{
	int		row;
	char	**copy_map;
	int		i;

	row = ft_colm_counter(map);
	copy_map = malloc(sizeof(char *) * (row + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		copy_map[i] = ft_strdup(map[i]);
		if (!copy_map[i])
		{
			ft_free(copy_map);
			ft_putstr_fd("Malloc Error\n", 2);
			return (NULL);
		}
		i++;
	}
	copy_map[i] = 0;
	return (copy_map);
}

void	path_finder(t_finder *f, int x, int y)
{
	if (f->map[x][y] == 'E')
		f->exit = 1;
	if (f->map[x][y] == '1' || f->map[x][y] == 'E')
		return ;
	if (f->map[x][y] == 'C')
		f->coin++;
	f->map[x][y] = '1';
	path_finder(f, x - 1, y);
	path_finder(f, x, y - 1);
	path_finder(f, x + 1, y);
	path_finder(f, x, y + 1);
}

int	is_game(char **map, t_map stat)
{
	t_finder	finder;
	int			player[2];

	ft_player(map, player);
	finder.map = ft_map_copy(map);
	if (!finder.map)
		return (-1);
	finder.coin = 0;
	finder.exit = 0;
	path_finder(&finder, player[0], player[1]);
	if (finder.coin != stat.coin)
		return (ft_free(finder.map), -1);
	else if (finder.exit != 1)
		return (ft_free(finder.map), -1);
	return (ft_free(finder.map), 1);
}
