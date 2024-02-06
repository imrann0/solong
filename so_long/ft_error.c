/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:26:30 by albozkur          #+#    #+#             */
/*   Updated: 2024/02/06 20:27:16 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"

void	ft_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char	*ft_get_next_line_error(char **line, char **res)
{
	if (line)
		free(line);
	if (res)
		free(res);
	return (NULL);
}

int	ft_check_error(t_map *map_stat)
{
	if (map_stat->player != 1)
		return (1);
	if (map_stat->exit != 1)
		return (1);
	if (map_stat->coin < 1)
		return (1);
	return (0);
}
