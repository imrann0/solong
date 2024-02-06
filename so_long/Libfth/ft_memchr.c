/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:30 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/16 11:00:41 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (len)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
		len--;
	}
	return (NULL);
}
