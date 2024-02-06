/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:15:10 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/21 14:37:24 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	i = 1;
	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	if (!new_dest && !new_src)
		return (NULL);
	if (new_dest > new_src)
	{
		while (i <= n)
		{
			new_dest[n - i] = new_src[n - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
