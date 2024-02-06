/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:13:08 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/21 14:48:52 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	size = len;
	if (start >= (unsigned int)ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len >= (unsigned int)ft_strlen(s + start))
		size = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
