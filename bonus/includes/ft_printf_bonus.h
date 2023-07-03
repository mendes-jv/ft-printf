/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:30:06 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/26 12:30:41 by jovicto2         ###   ########.fr       */
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

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxXobf%"
# endif

int	ft_printf(const char *format, ...);

typedef enum e_bool
{
	false = 0,
	true = 1
} t_bool;

typedef struct s_flags
{
	t_bool	hasMinus;
	t_bool	hasPlus;
	t_bool	hasSpace;
	t_bool	hasZero;
	t_bool	hasHashtag;
} t_flags;

typedef struct s_parameters
{
	t_flags	*flags;
	size_t	width;
	size_t	precision;
	char	specifer;
} t_parameters;

#endif
