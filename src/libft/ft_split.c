/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <thgabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:28:30 by thgabell          #+#    #+#             */
/*   Updated: 2022/06/01 17:06:09 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_words(char const *s, char c)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			nb_word++;
			while (!(s[i] == c) && s[i])
				i++;
		}
	}
	return (nb_word);
}

static char	*get_size_word(char const *s, char c, int *nb_char)
{
	int		count;
	int		i;
	char	*dest;

	count = 0;
	while (s[*nb_char] == c)
		(*nb_char)++;
	while (!(s[*nb_char + count] == c) \
		&& s[*nb_char + count])
		count++;
	dest = malloc((count + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < count)
	{
		dest[i] = s[*nb_char];
		i++;
		(*nb_char)++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		nb_char;
	int		i;
	char	**dest;

	if (!s)
		return (NULL);
	i = 0;
	nb_char = 0;
	nb_words = get_nb_words(s, c);
	dest = malloc((nb_words + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < nb_words)
	{
		dest[i] = get_size_word(s, c, &nb_char);
		if (dest[i] == NULL)
			while (i >= 0)
				free(dest[i--]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
