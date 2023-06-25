/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputhexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:41:21 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 19:20:06 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputhexa_fd(unsigned long nbr, int fd, char specifier)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 16 > 0)
		written_bytes += ft_lputhexa_fd(nbr / 16, fd, specifier);
	if (nbr / 16 > 9)
	{
		nbr -= 10;
		if (specifier == 'X')
			converter = nbr % 16 + 'A';
		else
			converter = nbr % 16 + 'a';
	}
	else
		converter = nbr % 16 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
