/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:44:29 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/06 13:44:36 by jovicto2         ###   ########.fr       */
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
		; // TODO
}

static char	*ft_apply_specifier(char specifier, va_list ap)
{
	char	*str;

	str = NULL;
	if (specifier == 's')
		str = va_arg(ap, char *); //TODO: verificar free()
	else if (specifier == 'p')
		str = ft_ptoa(va_arg(ap, size_t));
	else if (specifier == 'o')
		str = ft_otoa(va_arg(ap, size_t));
	else if (specifier == 'b')
		str = ft_btoa(va_arg(ap, size_t));
	else if (ft_strchr("di", specifier))
		str = ft_itoa(va_arg(ap, int));
	else if (specifier == 'u')
		str = ft_itoa(va_arg(ap, unsigned int));
	else if (ft_strchr("xX", specifier))
		str = ft_htoa(va_arg(ap, unsigned int));
	else if (specifier == 'f')
		str = ft_dtoa(va_arg(ap, double));
	else if (specifier == 'c')
		*str = va_arg(ap, int); //TODO: verificar free()
	else if (specifier == '%')
		*str = '%';
	return (str);
}

static size_t	ft_write_params(t_parameters *params)
{
	size_t	pb;

	pb = 0;
	return (pb);
}
