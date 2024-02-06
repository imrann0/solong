/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcter_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:39 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 20:29:42 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libfth/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

t_move	ft_move(int x, int y, int i, int j)
{
	t_move	move;

	move.x = x;
	move.y = y;
	move.i = i;
	move.j = j;
	return (move);
}

void	ft_map_swap(char **map, t_move m)
{
	char	c;

	c = map[m.x][m.y];
	map[m.x][m.y] = '0';
	map[m.x + m.i][m.y + m.j] = c;
}

int	press_close_key(t_img *game)
{
	ft_putstr_fd("\033[1;31m Game is closed\n", 1);
	mlx_destroy_window(game->data.mlx, game->data.win);
	free(game->data.mlx);
	ft_free(game->map);
	exit(1);
	return (1);
}

void	ft_put_image(t_data dt, t_img img, char **map)
{
	t_move	m;

	m = ft_move(0, 0, 0, 0);
	while (map[m.i] != NULL)
	{
		m.j = 0;
		m.x = 0;
		while (map[m.i][m.j] != '\0')
		{
			ft_mlx_put_error(dt, img, m, map);
			m.x += 32;
			m.j++;
		}
		m.y += 32;
		m.i++;
	}
}

void	ft_mlx_put_error(t_data dt, t_img img, t_move m, char **map)
{
	if (map[m.i][m.j] == '1')
		mlx_put_image_to_window(dt.mlx, dt.win, img.wall, m.x, m.y);
	else
		mlx_put_image_to_window(dt.mlx, dt.win, img.gro, m.x, m.y);
	if (map[m.i][m.j] == 'P')
		mlx_put_image_to_window(dt.mlx, dt.win, img.chr, m.x, m.y);
	else if (map[m.i][m.j] == 'C')
		mlx_put_image_to_window(dt.mlx, dt.win, img.coin, m.x, m.y);
	else if (map[m.i][m.j] == 'E')
		mlx_put_image_to_window(dt.mlx, dt.win, img.ext, m.x, m.y);
}
