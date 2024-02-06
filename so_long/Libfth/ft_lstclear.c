/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:58:09 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/19 17:38:25 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*temp;

	iter = *lst;
	while (iter)
	{
		del(iter -> content);
		temp = iter;
		iter = iter ->next;
		free(temp);
	}
	*lst = NULL;
}
