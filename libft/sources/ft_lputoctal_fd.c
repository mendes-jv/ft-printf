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

size_t	ft_lputoctal_fd(size_t nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 8 > 0)
		written_bytes += ft_lputoctal_fd(nbr / 8, fd);
	converter = nbr % 8 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
