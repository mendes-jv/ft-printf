/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:36:50 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/20 20:39:37 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
		substring = ft_calloc((len + 1), sizeof(char));
	else
		substring = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	if (substring)
	{
		if (len > ft_strlen(s) + 1)
			len = ft_strlen(s) + 1;
		ft_strlcpy(substring, (s + start), (len + 1));
	}
	else
		return (NULL);
	return (substring);
}
