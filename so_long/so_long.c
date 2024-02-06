/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:09:49 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 20:07:02 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libfth/libft.h"
#include "so_long.h"

t_path	ft_path(void)
{
	t_path	p;

	p.chr = "images/chr.xpm";
	p.coin = "images/gold.xpm";
	p.wall = "images/wall.xpm";
	p.ext = "images/door.xpm";
	p.gro = "images/ground.xpm";
	return (p);
}

void	ft_player(char **av, int *player)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'P')
			{
				player[0] = i;
				player[1] = j;
			}
			j++;
		}
		i++;
	}
}

int	main(int ar, char **av)
{
	char	**map;
	t_map	map_stat;

	if (ar == 2)
	{
		if (extension_control(av[1]) != 0)
			return (ft_putendl_fd("wrong file type", 2), 0);
		map = get_map(av[1]);
		if (!map)
			return (ft_putendl_fd("Map Error", 2), 0);
		map_stat = ft_check(map);
		if (map_stat.flag == -1)
			return (ft_putendl_fd("Map Check Error", 2), ft_free(map), 0);
		if (is_game(map, map_stat) == -1)
			return (ft_putendl_fd("Map Game Error", 2), ft_free(map), 0);
		init_mlx(map_stat, map);
		ft_free(map);
	}
	return (0);
}
