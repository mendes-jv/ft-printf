/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:45:07 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/24 04:48:04 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputstr_fd(char *s, int fd)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (!s)
		return (write(fd, NULL_STRING, ft_strlen(NULL_STRING)));
	while (*s)
		written_bytes += write(fd, s++, sizeof(char));
	return (written_bytes);
}
