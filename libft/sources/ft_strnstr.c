/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:47:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/16 18:48:32 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*first_occurrence;
	size_t	i;
	size_t	l_len;

	first_occurrence = NULL;
	i = 0;
	l_len = ft_strlen(little);
	while (big[i] && i < len && l_len)
	{
		if (!ft_strncmp((big + i), little, l_len) && (i + l_len <= len))
		{
			first_occurrence = (char *)(big + i);
			break ;
		}
		i++;
	}
	if (!l_len)
		first_occurrence = (char *)big;
	return (first_occurrence);
}
