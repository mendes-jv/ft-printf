/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputaddress_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:11:06 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 04:59:08 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputaddress_fd(unsigned long nbr, int fd)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (!nbr)
	{
		written_bytes += ft_lputstr_fd(NULL_STRING, fd);
		return (written_bytes);
	}
	written_bytes += ft_lputstr_fd("0x", fd);
	written_bytes += ft_lputhexa_fd(nbr, fd, 'x');
	return (written_bytes);
}
