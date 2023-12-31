/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:46:30 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/23 21:53:41 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef PRINTF_ERROR
#  define PRINTF_ERROR -1
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

// Mandatory
int	ft_printf(const char *format, ...);

#endif
