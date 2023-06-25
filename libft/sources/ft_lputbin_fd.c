/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputbin_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:22:41 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 19:22:41 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputbin_fd(unsigned long nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 2 > 0)
		written_bytes += ft_lputbin_fd(nbr / 2, fd);
	converter = nbr % 2 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
