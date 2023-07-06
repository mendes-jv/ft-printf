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
		str = ft_strdup(va_arg(ap, char *)); //verificar
	else if (specifier == '%')
		str = ft_strdup(&specifier);
	return (str);
}

static size_t	ft_write_params(t_parameters *params)
{
	size_t	pb;

	pb = 0;
	return (pb);
}
