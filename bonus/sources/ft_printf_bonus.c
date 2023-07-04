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
			params->converted = ft_apply_specifier(*(++format), ap);
			pb += ft_write_params(params);
			free(params->converted);
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
	while (!ft_strchr("0123456789", *format))
		;//TODO
}

static char	*ft_apply_specifier(char specifier, va_list ap)
{
	char	*str;

	str = NULL;
	if (specifier == 's')
		str = ft_lputstr_fd(va_arg(ap, char *), STDOUT_FD);
	else if (specifier == 'p')
		str = ft_lputaddress_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (specifier == 'o')
		str = ft_lputoctal_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (specifier == 'b')
		str = ft_lputbin_fd(va_arg(ap, size_t), STDOUT_FD);
	else if (ft_strchr("di", specifier))
		str = ft_lputnbr_fd(va_arg(ap, int), STDOUT_FD);
	else if (specifier == 'u')
		str = ft_lputnbr_fd(va_arg(ap, unsigned int), STDOUT_FD);
	else if (ft_strchr("xX", specifier))
		str = ft_lputhexa_fd(va_arg(ap, unsigned int), STDOUT_FD, specifier);
	else if (specifier == 'f')
		str = ft_lputdouble_fd(va_arg(ap, double), STDOUT_FD);
	else
		str = NULL; //TODO c e %
	return (str);
}

static size_t	ft_write_params(t_parameters *params)
{
	size_t	pb;

	pb = 0;
	return (pb);
}
