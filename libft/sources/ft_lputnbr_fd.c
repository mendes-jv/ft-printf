/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:08:06 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 19:14:22 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputnbr_fd(long nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		written_bytes += write(fd, "-", sizeof(char));
	}
	if (nbr / 10 > 0)
		written_bytes += ft_lputnbr_fd(nbr / 10, fd);
	converter = nbr % 10 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
