/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_params_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:09:11 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/22 22:36:45 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_manage_flags(t_parameters *params, ssize_t *conv_len,
				long *index, size_t *pb);

size_t	ft_write_params(t_parameters *params)
{
	long	index;
	size_t	pb;
	ssize_t	conv_len;

	pb = 0;
	index = 0;
	if (params->specifier == '%')
		return (write(STDOUT_FD, params->converted, sizeof(char)));
	if (params->flags->has_hashtag && *(params->converted) != '0')
		index += 2;
	if (params->specifier == 'c' && !*(params->converted))
		conv_len = sizeof(char);
	else
		conv_len = ft_strlen(params->converted);
	ft_manage_flags(params, &conv_len, &index, &pb);
	return (pb);
}

static void	ft_manage_flags(t_parameters *params, ssize_t *conv_len,
long *index, size_t *pb)
{
	if (params->flags->has_minus)
	{
		ft_apply_prefixes(params, pb);
		ft_apply_precision(params, conv_len, index, pb);
		ft_apply_conversion(params, conv_len, pb);
		ft_apply_width(params, conv_len, index, pb);
	}
	else
	{
		ft_apply_zero_flag(params, conv_len, index, pb);
		*(params->width) = ft_apply_width(params, conv_len, index, pb);
		ft_apply_precision(params, conv_len, index, pb);
		ft_apply_prefixes(params, pb);
		ft_apply_conversion(params, conv_len, pb);
	}
}
