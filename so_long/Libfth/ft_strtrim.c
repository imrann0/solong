/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:35:52 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/21 14:52:35 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char a, const char *set)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

static int	trim_start(char const *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && contains(s1[i], set))
		i++;
	return (i);
}

static int	trim_end(char const *s1, const char *set, int len)
{
	int	i;

	i = len - 1;
	while (i > 0 && contains(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = trim_start(s1, set);
	end = trim_end(s1, set, ft_strlen(s1));
	return (ft_substr(s1, start, end - start + 1));
}
