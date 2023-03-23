/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:06:15 by thgabell          #+#    #+#             */
/*   Updated: 2022/05/14 15:08:27 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n)
		{	
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
		return (dest);
	}	
	else
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
}
