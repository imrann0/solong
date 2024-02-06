/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:23:40 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/21 14:56:57 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	step_count(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		step;
	long int	nbl;

	nbl = n;
	step = step_count(nbl);
	str_num = (char *)malloc(sizeof(char) * (step + 1));
	if (!str_num)
		return (NULL);
	str_num[step] = '\0';
	if (nbl < 0)
		nbl *= -1;
	while (step > 0)
	{
		step--;
		str_num[step] = nbl % 10 + '0';
		nbl = nbl / 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}
