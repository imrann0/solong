/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:18:37 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/04 15:10:47 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Libfth/libft.h"

static int	read_loop(char **line, int fd)
{
	char	c[2];
	long	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, c, 1);
		if (bytes_read == 0)
			return (bytes_read);
		if (bytes_read == -1)
			return (free(*line), -1);
		c[1] = '\0';
		tmp = ft_strjoin(*line, c);
		if (!tmp)
			return (free(*line), -1);
		free(*line);
		*line = tmp;
		if (c[0] == '\n')
			return (bytes_read);
	}
	return (bytes_read);
}

int	get_next_line(int fd, char **line)
{
	int	bytes_read;

	if (fd < 0)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	bytes_read = read_loop(line, fd);
	return (bytes_read);
}
