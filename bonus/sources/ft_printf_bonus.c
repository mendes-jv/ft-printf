/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:03:04 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/06 18:08:25 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void		ft_check_flags(char *format, t_flags *flags);
static void		ft_check_mods(char *format, size_t *width, size_t *precision);
static char		*ft_apply_specifier(char specifier, va_list ap);
static size_t	ft_write_params(t_parameters *params);

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			pb;
	t_parameters	*params;

	pb = 0;
	params = (t_parameters *)ft_calloc(1, sizeof(t_parameters));
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_init_params(params);
			ft_check_flags((char *)++format, params->flags);
			ft_check_mods((char *)++format, params->width, params->precision);
			params->specifier = *(++format);
			params->converted = ft_apply_specifier(params->specifier, ap);
			pb += ft_write_params(params);
		}
		else
			pb += write(STDOUT_FD, &(*format), sizeof(char));
		format++;
	}
	va_end(ap);
	return (pb);
}

static void	ft_check_flags(char *format, t_flags *flags)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->has_minus = true;
		else if (*format == '+')
			flags->has_plus = true;
		else if (*format == ' ')
			flags->has_space = true;
		else if (*format == '0')
			flags->has_zero = true;
		else if (*format == '#')
			flags->has_hashtag = true;
		format++;
	}
}

static void	ft_check_mods(char *format, size_t *width, size_t *precision)
{
	size_t	index;
	char	*temp;

	index = 0;
	temp = NULL;
	if(format[index] == '.')
		format++;
	while (ft_strchr("0123456789", format[index]))
		index++;
	temp = ft_substr(format, 0, index);
	if (!index)
		return ;
	if (*(format - 1) == '.')
		*precision = ft_atoi(temp);
	else
	{
		*width = ft_atoi(temp);
		ft_check_mods(format, width, precision);
	}
	format += index;
	free(temp);
}

static char	*ft_apply_specifier(char specifier, va_list ap)
{
	char	*str;

	str = NULL;
	if (specifier == 's')
		str = ft_strdup(va_arg(ap, char *));
	else if (specifier == 'p')
		str = ft_ptoa(va_arg(ap, size_t));
	else if (specifier == 'o')
		str = ft_itoa_base(va_arg(ap, size_t), 8, OCTALS);
	else if (specifier == 'b')
		str = ft_itoa_base(va_arg(ap, size_t), 2, BINARIES);
	else if (ft_strchr("di", specifier))
		str = ft_itoa_base(va_arg(ap, int), 10, DECIMALS);
	else if (specifier == 'u')
		str = ft_itoa_base(va_arg(ap, unsigned int), 10, DECIMALS);
	else if (specifier == 'X')
		str = ft_itoa_base(va_arg(ap, unsigned int), 16, UPPER_HEXAS);
	else if (specifier == 'x')
		str = ft_itoa_base(va_arg(ap, unsigned int), 16, LOWER_HEXAS);
	else if (specifier == 'c')
		str = ft_strdup(va_arg(ap, char *)); // verificar
	else if (specifier == '%')
		str = ft_strdup(&specifier);
	return (str);
}

static size_t	ft_write_params(t_parameters *params)
{
	size_t	pb;
	size_t	index;
	size_t	conv_len;

	pb = 0;
	index = 0;
	if (params->flags->has_hashtag)
		index += 2;
	conv_len = ft_strlen(params->converted); 
	if (params->flags->has_minus)
	{
		if (params->flags->has_plus)
		{
			params->flags->has_space = false;
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "+", sizeof(char));
			else
				pb += write(STDOUT_FD, "-", sizeof(char));
		}
		if (params->flags->has_space)
		{
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "0", sizeof(char));
			else
				pb += write(STDOUT_FD, "-", sizeof(char));
		}
		if (params->flags->has_hashtag && ft_strrchr("xX", params->specifier))
		{
			params->flags->has_zero = false;
			pb += write(STDOUT_FD, "0", sizeof(char));
			if (ft_strrchr("xX", params->specifier))
				pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
		}
		pb += ft_lputstr_fd(params->converted, STDOUT_FD);
		if (*(params->precision))
		{
			params->flags->has_zero = false;
			while (index++ <= *(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space)
				pb += write(STDOUT_FD, "0", sizeof(char));
		}
		if (*(params->width))
			while (index++ <= *(params->width) - *(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space)
				pb += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		if (*(params->width))
			while (index++ <= *(params->width) - *(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space)
				pb += write(STDOUT_FD, " ", sizeof(char));
		if (*(params->precision))
		{
			params->flags->has_zero = false;
			while (index++ <= *(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space)
				pb += write(STDOUT_FD, "0", sizeof(char));
		}
		if (params->flags->has_hashtag && ft_strrchr("xX", params->specifier))
		{
			params->flags->has_zero = false;
			pb += write(STDOUT_FD, "0", sizeof(char));
			if (ft_strrchr("xX", params->specifier))
				pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
		}
		if (params->flags->has_zero)
			while (index++ <= *(params->width) - conv_len - params->flags->has_plus - params->flags->has_space)
				pb += write(STDOUT_FD, "0", sizeof(char));
		if (params->flags->has_plus)
		{
			params->flags->has_space = false;
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "+", sizeof(char));
			else
				pb += write(STDOUT_FD, "-", sizeof(char));
		}
		if (params->flags->has_space)
		{
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "0", sizeof(char));
			else
				pb += write(STDOUT_FD, "-", sizeof(char));
		}
		pb += ft_lputstr_fd(params->converted, STDOUT_FD);
	}
	ft_free_params(params);
	return (pb);
}
