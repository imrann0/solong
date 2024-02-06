/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:35:43 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 18:44:32 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libfth/libft.h"
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int	extension_control(char *ext)
{
	int	size;

	size = ft_strlen(ext) - 4;
	if (size < 0)
		return (-1);
	return (ft_strncmp(&ext[size], ".ber", 5));
}

char	*ft_reading(int fd)
{
	char	*line;
	char	*res;
	int		byte;
	char	*tmp;

	byte = 1;
	res = ft_strdup("");
	if (!res)
		return (0);
	while (byte)
	{
		byte = get_next_line(fd, &line);
		if (byte == -1)
			return (ft_get_next_line_error(&line, &res));
		tmp = ft_strjoin(res, line);
		if (!tmp)
			return (ft_get_next_line_error(&line, &res));
		free(res);
		res = tmp;
		free(line);
	}
	return (res);
}

char	**get_map(char *av)
{
	char	*res;
	char	**map;
	char	*tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	res = ft_reading(fd);
	close(fd);
	if (!res)
		return (NULL);
	tmp = ft_strtrim(res, "\n");
	if (!tmp)
		return (free(res), NULL);
	free(res);
	res = tmp;
	if (ft_new_line(res))
		return (free(res), NULL);
	map = ft_split(res, '\n');
	free(res);
	if (!map)
		return (NULL);
	return (map);
}

int	ft_new_line(char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n' && res[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_colm_counter(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
