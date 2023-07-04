/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:35:18 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/03 22:52:02 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_init_flags(t_flags *flags);

void	ft_init_params(t_parameters *params)
{
	ft_init_flags(params->flags);
	*(params->width) = 0;
	*(params->precision) = 0;
}

static void	ft_init_flags(t_flags *flags)
{
	flags->has_minus = false;
	flags->has_plus = false;
	flags->has_space = false;
	flags->has_zero = false;
	flags->has_hashtag = false;
}
