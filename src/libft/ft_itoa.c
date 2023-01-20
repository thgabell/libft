/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgabell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:17:23 by thgabell          #+#    #+#             */
/*   Updated: 2022/05/09 16:17:45 by thgabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}

static void	ptr_builder(char *ptr, int *ptr_n, int *ptr_n_len)
{
	if (*ptr_n < 0)
	{
		if (*ptr_n == -2147483648)
		{
			*ptr_n /= 10;
			ptr[10] = '8';
			ptr[11] = 0;
			*ptr_n_len -= 2;
		}
		else
			ptr[(*ptr_n_len)--] = 0;
		*ptr_n = *ptr_n * -1;
		ptr[0] = '-';
	}
	else
		ptr[(*ptr_n_len)--] = 0;
	while (*ptr_n)
	{
		ptr[(*ptr_n_len)--] = *ptr_n % 10 + '0';
		*ptr_n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		*ptr_n;
	int		*ptr_n_len;
	int		n_len;

	n_len = get_len_int(n);
	ptr_n = &n;
	ptr_n_len = &n_len;
	ptr = malloc(sizeof(char) * (get_len_int(n) + 1));
	if (!ptr)
		return (NULL);
	if (n == 0)
	{
		ptr[0] = '0';
		ptr[1] = 0;
		return (ptr);
	}
	ptr_builder(ptr, ptr_n, ptr_n_len);
	return (ptr);
}
