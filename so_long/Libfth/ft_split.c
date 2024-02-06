/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:50:05 by albozkur          #+#    #+#             */
/*   Updated: 2023/12/26 13:24:56 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**clean(char **ptr)
{
	char	**str;

	str = ptr;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(ptr);
	return (NULL);
}

static int	luzera(const char *s, char c)
{
	if (!ft_strchr(s, c))
		return (ft_strlen(s));
	else
		return (ft_strchr(s, c) - s);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	int		world_len;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			world_len = luzera(s, c);
			lst[i] = ft_substr(s, 0, world_len);
			if (!lst[i])
				return (clean(lst));
			i++;
			s += world_len;
		}
	}
	lst[i] = NULL ;
	return (lst);
}
