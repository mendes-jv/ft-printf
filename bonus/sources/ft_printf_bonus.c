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

static size_t	ft_write_params(t_parameters *params);

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			pb;
	t_parameters	*params;

	pb = 0;
	params = NULL;
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = (t_parameters *)ft_calloc(1, sizeof(t_parameters));
			format = ft_apply_params(params, (char *)format, ap);
			pb += ft_write_params(params);
			ft_free_params(params);
		}
		else
			pb += write(STDOUT_FD, &(*format), sizeof(char));
		format++;
	}
	va_end(ap);
	return (pb);
}

char	*ft_check_flags(char *format, t_flags *flags)
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
	return (format);
}

char	*ft_check_mods(char *format, size_t *width, size_t *precision)
{
	size_t	index;
	char	*temp;

	index = 0;
	temp = NULL;
	if(format[index] == '.')
		format++;
	while (ft_strchr("0123456789", format[index]))
		index++;
	if (!index)
		return (format);
	temp = ft_substr(format, 0, index);
	if (*(format - 1) == '.')
	{
		*precision = ft_atoi(temp);
		format += index;
	}
	else
	{
		*width = ft_atoi(temp);
		format = ft_check_mods(format + index, width, precision);
	}
	free(temp);
	return (format);
}

char	*ft_apply_specifier(char specifier, va_list ap)
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
		str = ft_ctoa(va_arg(ap, int));
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
	if (params->flags->has_hashtag && *(params->converted) != '0')
		index += 2;
	if(params->specifier == 'c' && !*(params->converted))
		conv_len = sizeof(char);
	else
		conv_len = ft_strlen(params->converted); 
	if (params->flags->has_minus)
	{
		if (params->flags->has_plus)
		{
			params->flags->has_space = false;
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "+", sizeof(char));
		}
		if (params->flags->has_space && ft_strchr("di", params->specifier))
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, " ", sizeof(char));
		if (params->flags->has_hashtag && ft_strchr("xX", params->specifier) && *(params->converted) != '0')
		{
			params->flags->has_zero = false;
			pb += write(STDOUT_FD, "0", sizeof(char));
			if (ft_strrchr("xX", params->specifier))
				pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
		}
		if (params->specifier == 'c' && !*(params->converted))
			pb += write(STDOUT_FD, &*(params->converted), sizeof(char));
		else
			pb += ft_lputstr_fd(params->converted, STDOUT_FD);
		if (*(params->width))
			while ((long)index++ < (long)(*(params->width) - *(params->precision) - conv_len - params->flags->has_plus))
				pb += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		if (params->flags->has_zero)
		{
			if (ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
				pb += write(STDOUT_FD, "-", sizeof(char));
			while ((long)index++ < (long)(*(params->width) - conv_len - params->flags->has_plus - params->flags->has_space))
				pb += write(STDOUT_FD, "0", sizeof(char));
			*(params->width) = 0;
		}
		if (*(params->width))
			while ((long)index++ < (long)(*(params->width) - *(params->precision) - conv_len - params->flags->has_plus))
				pb += write(STDOUT_FD, " ", sizeof(char));
		if (*(params->precision) && params->specifier != 's')
		{
			params->flags->has_zero = false;
			if (ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			{
				pb += write(STDOUT_FD, "-", sizeof(char));
				conv_len--;
			}
			while ((long)index++ < (long)(*(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space))
				pb += write(STDOUT_FD, "0", sizeof(char));
		}
		if (params->flags->has_hashtag && ft_strchr("xX", params->specifier) && *(params->converted) != '0')
		{
			params->flags->has_zero = false;
			pb += write(STDOUT_FD, "0", sizeof(char));
			if (ft_strrchr("xX", params->specifier))
				pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
		}
		if (params->flags->has_plus)
		{
			params->flags->has_space = false;
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, "+", sizeof(char));
		}
		if (params->flags->has_space && ft_strchr("di", params->specifier))
			if (ft_atoi(params->converted) >= 0)
				pb += write(STDOUT_FD, " ", sizeof(char));
		if (params->specifier == 'c' && !*(params->converted))
			pb += write(STDOUT_FD, &*(params->converted), sizeof(char));
		else if ((params->flags->has_zero || *(params->precision)) && ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			pb += ft_lputstr_fd(params->converted + 1, STDOUT_FD);
		else if (*(params->precision) <= conv_len && params->specifier == 's' && !(params->flags->has_space))
				pb += write(STDOUT_FD, params->converted, *(params->precision));
		else
			pb += ft_lputstr_fd(params->converted, STDOUT_FD);
	}
	return (pb);
}
