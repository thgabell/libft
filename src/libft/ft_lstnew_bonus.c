/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:34:17 by thgabell          #+#    #+#             */
/*   Updated: 2022/05/20 16:56:30 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_ptr;

	s_ptr = malloc(sizeof(t_list));
	if (!s_ptr)
		return (NULL);
	s_ptr->content = content;
	s_ptr->next = NULL;
	return (s_ptr);
}
