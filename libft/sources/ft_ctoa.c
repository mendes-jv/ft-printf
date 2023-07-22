/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:32:18 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/10 18:42:52 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_ctoa(char c)
{
	char	*string;

	if (c)
	{
		string = ft_calloc(2, sizeof(char));
		*string = c;
	}
	else
		string = ft_calloc(1, sizeof(char));
	return (string);
}
