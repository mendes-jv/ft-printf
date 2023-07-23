/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_params_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:35:18 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/22 21:50:23 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_init_flags(t_flags *flags);
static void	ft_init_mods(ssize_t *width, ssize_t *precision);

void	ft_init_params(t_parameters *params)
{
	params->flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	params->width = (ssize_t *)ft_calloc(1, sizeof(ssize_t));
	params->precision = (ssize_t *)ft_calloc(1, sizeof(ssize_t));
	ft_init_flags(params->flags);
	ft_init_mods(params->width, params->precision);
}

static void	ft_init_flags(t_flags *flags)
{
	flags->has_minus = false;
	flags->has_plus = false;
	flags->has_space = false;
	flags->has_zero = false;
	flags->has_hashtag = false;
}

static void	ft_init_mods(ssize_t *width, ssize_t *precision)
{
	*width = NOT_SPEC;
	*precision = NOT_SPEC;
}

char	*ft_apply_params(t_parameters *params, char *format, va_list ap)
{
	ft_init_params(params);
	format = ft_check_flags((char *)++format, params->flags);
	format = ft_check_mods((char *)format, params->width, params->precision);
	params->specifier = *format;
	params->converted = ft_apply_specifier(params->specifier, ap);
	return ((char *)format);
}

void	ft_free_params(t_parameters *params)
{
	free(params->flags);
	free(params->width);
	free(params->precision);
	free(params->converted);
	free(params);
}
