/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:11:15 by thgabell          #+#    #+#             */
/*   Updated: 2022/05/09 15:13:51 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s) + 1;
	while (i < length)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
		i++;
	}
	return (NULL);
}
