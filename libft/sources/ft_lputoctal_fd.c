/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputoctal_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:18:15 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 19:22:16 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputoctal_fd(unsigned long nbr, int fd, char specifier)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (nbr / 8 > 0)
		written_bytes += ft_lputhexa_fd(nbr / 8, fd);
	written_bytes += write(fd, nbr % 8 + '0', sizeof(char));
	return (written_bytes);
}
