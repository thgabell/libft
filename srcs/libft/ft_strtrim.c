/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:20:21 by thgabell          #+#    #+#             */
/*   Updated: 2022/06/01 17:00:48 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		s1_len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	while (s1[i] && is_set(s1[i], set))
		i++;
	while (s1_len > i && is_set(s1[s1_len - 1], set))
		s1_len--;
	ptr = (char *)malloc(sizeof(*s1) * (s1_len - i + 1));
	if (!ptr)
		return (NULL);
	while (i < s1_len)
		ptr[j++] = s1[i++];
	ptr [j] = 0;
	return (ptr);
}
