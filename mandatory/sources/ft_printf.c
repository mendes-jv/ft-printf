/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:47:20 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/22 13:47:54 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_apply_specifier(char specifier, va_list ap);
static size_t	ft_write_specifiers(char specifier, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	pb;

	pb = 0;
	if (!format)
		return (PRINTF_ERROR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			pb += ft_apply_specifier(*(format + 1), ap);
		else
			pb += write(STDOUT_FD, &(*format), sizeof(char));
		format++;
	}
	va_end(ap);
	return (pb);
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
		pb += ft_lputhexa_fd(va_arg(ap, size_t), STDOUT_FD, specifier);
	else if (specifier == 'f')
		pb += ft_lputdouble_fd(va_arg(ap, double), STDOUT_FD);
	else
		ft_write_specifiers(specifier, ap);
	return (pb);
}

static size_t	ft_write_specifiers(char specifier, va_list ap)
{
	size_t	pb;

	pb = 0;
	if (specifier == 'c')
		specifier = va_arg(ap, int);
	if (specifier != '%')
		pb += write(STDOUT_FD, "%", sizeof(char));
	pb += write(STDOUT_FD, &specifier, sizeof(char));
	return (pb);
}
