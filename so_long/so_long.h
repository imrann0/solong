/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:08:52 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 20:27:20 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_map
{
	int	player;
	int	exit;
	int	coin;
	int	pcoin;
	int	stap;
	int	x;
	int	y;
	int	flag;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_img
{
	char	**map;
	void	*wall;
	void	*chr;
	void	*gro;
	void	*coin;
	void	*ext;
	t_data	data;
	t_map	stat;
}	t_img;

typedef struct s_path
{
	char	*wall;
	char	*chr;
	char	*gro;
	char	*coin;
	char	*ext;
}	t_path;

typedef struct s_move
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_move;

typedef struct s_finder
{
	char	**map;
	int		coin;
	int		exit;
}	t_finder;

//so_long.c
void	ft_player(char **av, int *player);
t_path	ft_path(void);
//utils.c
int		extension_control(char *ext);
int		ft_colm_counter(char **map);
char	*ft_reading(int fd);
char	**get_map(char *av);
int		ft_new_line(char *res);

//ft_check.c
int		ft_rectangle(char **map, int row, int cols);
int		ft_row_length(char **map, int row, int cols);
int		ft_counter(char **map, t_map *map_stat, int size);
int		ft_charcter_check(char *str, t_map *map_stat, int size);
t_map	ft_check(char **map);

//ft_error.c
void	ft_free(char **av);
int		ft_check_error(t_map *map_stat);
char	*ft_get_next_line_error(char **line, char **res);

// ft_get_next_line.c
int		get_next_line(int fd, char **line);

// ft_charcter.c
void	ft_charcter_move(t_img *img, t_move move);
void	ft_put(t_img *img, t_move move, int *p);
int		key_hook(int keycode, t_img *img);
void	init_mlx(t_map st, char **map);
int		ft_mlx_image_error(t_img *img, t_data *data, t_path p);

//charcter_utils.c
t_move	ft_move(int x, int y, int i, int j);
void	ft_map_swap(char **map, t_move m);
int		press_close_key(t_img *game);
void	ft_put_image(t_data dt, t_img img, char **map);
void	ft_mlx_put_error(t_data dt, t_img img, t_move m, char **map);

//pathfinder.c
char	**ft_map_copy(char **map);
void	path_finder(t_finder *f, int x, int y);
int		is_game(char **map, t_map stat);
#endif
