/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_params_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:09:11 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/22 16:59:13 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

size_t	ft_write_params(t_parameters *params)
{
	long	index;
	size_t	pb;
	ssize_t	conv_len;

	pb = 0;
	index = 0;
	if (params->specifier == '%')
		return (write(STDOUT_FD, params->converted, sizeof(char)));
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
		if (params->flags->has_hashtag && ft_strchr("oxX", params->specifier) && *(params->converted) != '0')
		{
			pb += write(STDOUT_FD, "0", sizeof(char));
			if (ft_strrchr("xX", params->specifier))
				pb += write(STDOUT_FD, &(params->specifier), sizeof(char));
		}
		if (*(params->precision) > 0 && params->specifier != 's')
		{
			if (ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			{
				pb += write(STDOUT_FD, "-", sizeof(char));
				conv_len--;
			}
			while (index++ < (long)(*(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space))
				pb += write(STDOUT_FD, "0", sizeof(char));
			index = 0;
		}
		if (params->specifier == 'c' && !*(params->converted))
			pb += write(STDOUT_FD, &*(params->converted), sizeof(char));
		else if ((*(params->precision) > 0) && ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			pb += ft_lputstr_fd(params->converted + 1, STDOUT_FD);
		else if (!*(params->precision) && *(params->width) && *(params->converted) == '0')
		{
			if (*(params->width) != NOT_SPECIFIED)
				while (conv_len--)
					pb += write(STDOUT_FD, " ", sizeof(char));
		}
		else if (*(params->precision) != NOT_SPECIFIED && *(params->precision) < conv_len && params->specifier == 's' && !(params->flags->has_space))
		{
			if (ft_strncmp((params->converted), NULL_STRING, conv_len))
			{
				pb += write(STDOUT_FD, params->converted, *(params->precision));
				conv_len = *(params->precision);
			}
		}
		else
			pb += ft_lputstr_fd(params->converted, STDOUT_FD);
		if (*(params->width))
		{
			if (conv_len <= *(params->precision) && params->specifier != 's')
				*(params->width) = *(params->width) - *(params->precision) - (ft_atoi(params->converted) < 0 || *(params->converted) == '0') + conv_len;	
			while (index++ < (long)(*(params->width) - conv_len - params->flags->has_plus))
				pb += write(STDOUT_FD, " ", sizeof(char));
		}
	}
	else
	{
		if (params->flags->has_zero && *(params->precision) == NOT_SPECIFIED)
		{
			if (ft_atoi(params->converted) < 0 && ft_strchr("di", params->specifier))
				pb += write(STDOUT_FD, "-", sizeof(char));
			while (index++ < (long)(*(params->width) - conv_len - params->flags->has_plus - params->flags->has_space))
				pb += write(STDOUT_FD, "0", sizeof(char));
			*(params->width) = 0;
		}
		if (*(params->width))
		{
			if (conv_len <= *(params->precision) && params->specifier != 's')
				*(params->width) = *(params->width) - *(params->precision) - (ft_atoi(params->converted) < 0) + conv_len;
			else if (conv_len > *(params->precision) && params->specifier == 's' && *(params->precision) != NOT_SPECIFIED)
				*(params->width) = *(params->width) - *(params->precision) + conv_len;
			while (index++ < (long)(*(params->width) - conv_len - params->flags->has_plus))
				pb += write(STDOUT_FD, " ", sizeof(char));
			index = 0;
		}
		if (*(params->precision) > 0 && params->specifier != 's')
		{
			if (ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			{
				pb += write(STDOUT_FD, "-", sizeof(char));
				conv_len--;
			}
			while (index++ < (long)(*(params->precision) - conv_len - params->flags->has_plus - params->flags->has_space))
				pb += write(STDOUT_FD, "0", sizeof(char));
		}
		if (params->flags->has_hashtag && ft_strchr("oxX", params->specifier) && *(params->converted) != '0')
		{
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
		else if (((params->flags->has_zero && *(params->precision)) || *(params->precision) > 0) && ft_atoi((params->converted)) < 0 && ft_strchr("di", params->specifier))
			pb += ft_lputstr_fd(params->converted + 1, STDOUT_FD);
		else if (!*(params->precision) && *(params->width) > 0 && *(params->converted) == '0')
			while (conv_len--)
				pb += write(STDOUT_FD, " ", sizeof(char));
		else if (!*(params->precision) && *(params->width) && *(params->converted) == '0')
		{
			if (*(params->width) != NOT_SPECIFIED)
				while (conv_len--)
					pb += write(STDOUT_FD, " ", sizeof(char));
		}
		else if (*(params->precision) != NOT_SPECIFIED && *(params->precision) < conv_len && params->specifier == 's' && !(params->flags->has_space))
		{
			if (ft_strncmp((params->converted), NULL_STRING, conv_len))
				pb += write(STDOUT_FD, params->converted, *(params->precision));
		}
		else
			pb += ft_lputstr_fd(params->converted, STDOUT_FD);
	}
	return (pb);
}
