/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:31:07 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/26 12:31:32 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static size_t	ft_apply_specifier(char, va_list);
static size_t	ft_write_specifiers(char, va_list);
static void	ft_check_flags(char *, t_flags*);

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	size_t			pb;
	t_parameters	*parameters;

	pb = 0;
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_flags((char *)++format, parameters->flags);
			pb += ft_apply_specifier(*(++format), ap);
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
	if (format == '-')
		flags->hasMinus = true;
	else if (format == '+')
		ft_;
	else if (format == ' ')
		ft_;
	else if (format == '0')
		ft_;
	else if (format == '#')
		ft_;
	else
		ft_check_output_width_and_precision(++flags);
	return ();
}

static void ft_check_output_width_and_precision(char *string, char)
{
	while (!ft_strchr("0123456789", *string))
		store_number;

	return ();
}

static size_t	ft_apply_specifier(char specifier, va_list ap)
{
	size_t	pb;

	pb = 0;
	if (specifier == 's')
		pb += ft_lputstr_fd(va_arg(ap, char *), STDOUT_FD);
	else if (specifier == 'p')
		pb += ft_lputaddress_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (specifier == 'o')
		pb += ft_lputoctal_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (specifier == 'b')
		pb += ft_lputbin_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (ft_strchr("di", specifier))
		pb += ft_lputnbr_fd(va_arg(ap, int), STDOUT_FD);
	else if (specifier == 'u')
		pb += ft_lputnbr_fd(va_arg(ap, unsigned int), STDOUT_FD);
	else if (ft_strchr("xX", specifier))
		pb += ft_lputhexa_fd(va_arg(ap, unsigned int), STDOUT_FD, specifier);
	else if (specifier == 'f')
		pb += ft_lputdouble_fd(va_arg(ap, double), STDOUT_FD);
	else
		pb += ft_write_specifiers(specifier, ap);
	return (pb);
}

static size_t	ft_write_specifiers(char specifier, va_list ap)
{
	size_t	pb;

	pb = 0;
	if (specifier == 'c')
		specifier = va_arg(ap, int);
	else if (specifier != '%')
		pb += write(STDOUT_FD, "%", sizeof(char));
	pb += write(STDOUT_FD, &specifier, sizeof(char));
	return (pb);
}
