/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:42:04 by thgabell          #+#    #+#             */
/*   Updated: 2022/06/01 17:02:14 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static char	*build_ptr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[start + i] && len - i)
		i++;
	ptr = (char *)malloc(sizeof(*s) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[start] && len)
	{
		ptr[i] = s[start];
		start++;
		i++;
		len--;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		return (build_ptr(s, start, len));
	else
	{
		ptr = (char *)malloc(sizeof(char));
		ptr[0] = 0;
		return (ptr);
	}
}
