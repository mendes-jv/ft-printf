/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:22 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/18 15:17:23 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*destiny;
	size_t	source_length;

	source_length = ft_strlen(s) + 1;
	destiny = (char *)malloc(source_length);
	if (destiny)
		ft_strlcpy(destiny, s, source_length);
	return (destiny);
}
