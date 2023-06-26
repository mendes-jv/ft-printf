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

#include "../../libft/includes/libft.h"

size_t	ft_lputhexa_fd(size_t nbr, int fd, char specifier)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 16 > 0)
		written_bytes += ft_lputhexa_fd(nbr / 16, fd, specifier);
	converter = nbr % 16;
	if (converter > 9)
	{
		converter -= 10;
		if (specifier == 'X')
			converter += 'A';
		else
			converter += 'a';
	}
	else
		converter += '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
