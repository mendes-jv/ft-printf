/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:37:00 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/20 22:41:08 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	string = (char *)malloc(length + ft_strlen(s2) + 1);
	if (string && s1 && s2)
	{
		ft_strlcpy(string, s1, length + 1);
		while (*s2)
			string[length++] = *s2++;
		string[length] = '\0';
	}
	return (string);
}
