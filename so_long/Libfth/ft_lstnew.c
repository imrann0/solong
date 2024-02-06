/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:09 by albozkur          #+#    #+#             */
/*   Updated: 2023/10/14 12:00:02 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*hade;

	hade = (t_list *)malloc(sizeof(t_list));
	if (!hade)
		return (NULL);
	hade->content = content;
	hade->next = NULL;
	return (hade);
}
