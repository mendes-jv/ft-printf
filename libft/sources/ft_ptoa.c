/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:17:43 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/06 18:17:45 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptoa (size_t nbr)
{
	char	*string;
	char	*temp;

	temp = ft_itoa_base(nbr, 16, LOWER_HEXAS);
	string = ft_strjoin("0x", temp);
	free(temp);

	return(string);
}
