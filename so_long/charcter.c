/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:47 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 20:30:54 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "Libfth/libft.h"
#include "minilibx/mlx.h"

void	ft_charcter_move(t_img *img, t_move move)
{
	int	p[2];

	ft_player(img->map, p);
	if (img->map[p[0] + move.i][p[1] + move.j] == '1')
		return ;
	else if (img->map[p[0] + move.i][p[1] + move.j] == 'C')
		img->stat.pcoin++;
	else if (img->map[p[0] + move.i][p[1] + move.j] == 'E')
	{
		if (img->stat.coin == img->stat.pcoin)
		{
			ft_putstr_fd("\n\033[1;32m Game Over\n", 1);
			mlx_destroy_window(img->data.mlx, img->data.win);
			free(img->data.mlx);
			ft_free(img->map);
			exit(EXIT_SUCCESS);
		}
		return ;
	}
	ft_put(img, move, p);
}

void	ft_put(t_img *img, t_move move, int *p)
{
	mlx_put_image_to_window(img->data.mlx, img->data.win,
		img->gro, (p[1] * 32), (p[0] * 32));
	mlx_put_image_to_window(img->data.mlx, img->data.win,
		img->chr, (p[1] * 32) + move.x, (p[0] * 32) + move.y);
	ft_map_swap(img->map, ft_move(p[0], p[1], move.i, move.j));
	img->stat.stap++;
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(img->stat.stap, 1);
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 13)
		ft_charcter_move(img, ft_move(0, -32, -1, 0));
	else if (keycode == 0)
		ft_charcter_move(img, ft_move(-32, 0, 0, -1));
	else if (keycode == 1)
		ft_charcter_move(img, ft_move(0, 32, 1, 0));
	else if (keycode == 2)
		ft_charcter_move(img, ft_move(32, 0, 0, 1));
	else if (keycode == 53)
	{
		ft_putstr_fd("\033[1;31m Game is closed\n", 1);
		mlx_destroy_window(img->data.mlx, img->data.win);
		free(img->data.mlx);
		ft_free(img->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	init_mlx(t_map st, char **map)
{
	t_data	data;
	t_img	img;
	t_path	p;

	p = ft_path();
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_putendl_fd("Mlx init Error", 2));
	data.win = mlx_new_window(data.mlx, (st.x) * 32, st.y * 32, "SoLong");
	if (!data.win)
		return (free(data.mlx), ft_putendl_fd("Window Error", 2));
	if (ft_mlx_image_error(&img, &data, p))
		return (ft_putendl_fd("İmg Error", 2));
	ft_put_image(data, img, map);
	img.map = map;
	img.data = data;
	img.stat = st;
	mlx_hook(data.win, 17, 0, press_close_key, &img);
	mlx_key_hook(data.win, key_hook, &img);
	mlx_loop(data.mlx);
}

int	ft_mlx_image_error(t_img *img, t_data *data, t_path p)
{
	int	w;
	int	h;

	img->wall = mlx_xpm_file_to_image(data->mlx, p.wall, &w, &h);
	if (!img->wall)
		return (1);
	img->chr = mlx_xpm_file_to_image(data->mlx, p.chr, &w, &h);
	if (!img->chr)
		return (free(img->wall), 1);
	img->gro = mlx_xpm_file_to_image(data->mlx, p.gro, &w, &h);
	if (!img->gro)
		return (free(img->chr), free(img->wall), 1);
	img->coin = mlx_xpm_file_to_image(data->mlx, p.coin, &w, &h);
	if (!img->coin)
		return (free(img->chr), free(img->wall), free(img->gro), 1);
	img->ext = mlx_xpm_file_to_image(data->mlx, p.ext, &w, &h);
	if (!img->ext)
		return (free(img->chr), free(img->wall),
			free(img->gro), free(img->chr), 1);
	return (0);
}
