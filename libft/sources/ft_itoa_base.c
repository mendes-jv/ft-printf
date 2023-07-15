/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:34:37 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/06 12:34:40 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_ilen(long long nbr, size_t base_len, const char *base);

char	*ft_itoa_base(long long nbr, size_t base_len, const char *base)
{
	char	*string;
	size_t	length;
	size_t	checker;

	length = ft_ilen(nbr, base_len, base);
	string = ft_calloc(length + 1, sizeof(char));
	checker = 0;
	if (!string)
		return (NULL);
	if (nbr <= 0)
	{
		nbr = -nbr;
		if (ft_strncmp(base, UPPER_HEXAS, base_len) || ft_strncmp(base, LOWER_HEXAS, base_len))
		{
			*string = '-';
			checker++;
		}
	}
	while (length > checker)
	{
		string[--length] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (string);
}

static size_t	ft_ilen(long long nbr, size_t base_len, const char *base)
{
	size_t	counter;

	counter = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		if (base == &UPPER_HEXAS || base == &LOWER_HEXAS)
			counter++;
	}
	while (nbr)
	{
		nbr /= base_len;
		counter++;
	}
	return (counter);
}
