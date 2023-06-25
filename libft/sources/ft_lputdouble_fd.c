/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputdouble_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:35:54 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 19:41:06 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputdouble_fd(double nbr, int fd, char specifier)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		written_bytes += write(fd, "-", sizeof(char));
	}
	written_bytes += ft_lputnbr_fd((int)nbr, fd);
	nbr -= (int)nbr;
	written_bytes += write(fd, ".", sizeof(char));
	while (((int)(nbr * 10)) / 10 > 0)
	{
		nbr *= 10.0;
		written_bytes += write(fd, (int)nbr % 10 + '0', sizeof(char));
		nbr -= (int)nbr;
	}
	return (written_bytes);
}
