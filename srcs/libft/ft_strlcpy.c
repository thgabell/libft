/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:49:26 by thgabell          #+#    #+#             */
/*   Updated: 2022/05/05 12:56:34 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if ((unsigned int)size != 0)
	{
		while (src[i] && i < (unsigned int)size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((size_t)j);
}
