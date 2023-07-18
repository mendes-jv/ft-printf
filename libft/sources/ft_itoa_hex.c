/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:37:53 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/15 16:41:29 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_ilen(unsigned long long nbr, size_t base);

char	*ft_itoa_hex(unsigned long long nbr, size_t base_len, const char *base)
{
	char	*string;
	size_t	length;

	length = ft_ilen(nbr, base_len);
	string = ft_calloc(length + 1, sizeof(char));
	if (!string)
		return (NULL);
	if (!nbr)
	{
		*string = '0';
		return (string);
	}
	while (length > 0)
	{
		string[--length] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (string);
}

static size_t	ft_ilen(unsigned long long nbr, size_t base_len)
{
	size_t	counter;

	counter = 0;
	if (!nbr)
		counter++;
	while (nbr)
	{
		nbr /= base_len;
		counter++;
	}
	return (counter);
}
