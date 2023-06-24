/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputhexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:41:21 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 04:58:52 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputhexa_fd(unsigned long nbr, int fd, char specifier)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		written_bytes += write(fd, "-", 1);
	}
	if (nbr / 16 > 0)
		written_bytes += ft_lputhexa_fd(nbr / 16, fd);
	if (nbr / 16 > 9)
	{
		nbr -= 10;
		if (specifier == 'X')
			converter = 'A';
		else
			converter = 'a';
	}
	else
		converter = '0';
	written_bytes += write(fd, nbr % 16 + converter, sizeof(char));
	return (written_bytes);
}
