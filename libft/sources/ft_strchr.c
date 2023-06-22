/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:00:56 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/10 22:51:31 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*first_occurrence;

	first_occurrence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			first_occurrence = (char *)s;
			break ;
		}
		s++;
	}
	if (!c || *s == (unsigned char)c)
		first_occurrence = (char *)s;
	return (first_occurrence);
}
