/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:04:59 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/13 18:05:11 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*first_occurrence;

	first_occurrence = NULL;
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			first_occurrence = (unsigned char *)s;
			break ;
		}
		s++;
	}
	return (first_occurrence);
}
