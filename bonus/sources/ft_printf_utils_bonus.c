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
static void	ft_init_mods(size_t *width, size_t *precision);

void	ft_init_params(t_parameters *params)
{
	params->flags = (t_flags *)ft_calloc(1, sizeof(t_flags));
	params->width = (size_t *)ft_calloc(1, sizeof(size_t));
	params->precision = (size_t *)ft_calloc(1, sizeof(size_t));
	ft_init_flags(params->flags);
	ft_init_mods(params->width, params->precision);
}

void	ft_free_params(t_parameters *params)
{
	free(params->flags);
	free(params->width);
	free(params->precision);
	free(params->converted);
	free(params);
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

static void	ft_init_flags(t_flags *flags)
{
	flags->has_minus = false;
	flags->has_plus = false;
	flags->has_space = false;
	flags->has_zero = false;
	flags->has_hashtag = false;
}

static void	ft_init_mods(size_t *width, size_t *precision)
{
	*width = 0;
	*precision = 0;
}
