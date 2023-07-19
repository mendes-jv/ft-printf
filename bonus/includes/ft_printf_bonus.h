/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:30:06 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/03 22:51:27 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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

# ifndef NOT_SPECIFIED
#  define NOT_SPECIFIED -1
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxXobf%"
# endif

# ifndef UPPER_HEXAS
#  define UPPER_HEXAS "0123456789ABCDEF"
# endif

# ifndef LOWER_HEXAS
#  define LOWER_HEXAS "0123456789abcdef"
# endif

# ifndef DECIMALS
#  define DECIMALS "0123456789"
# endif

# ifndef OCTALS
#  define OCTALS "01234567"
# endif

# ifndef BINARIES
#  define BINARIES "01"
# endif

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_flags
{
	t_bool	has_minus;
	t_bool	has_plus;
	t_bool	has_space;
	t_bool	has_zero;
	t_bool	has_hashtag;
}			t_flags;

typedef struct s_parameters
{
	t_flags	*flags;
	ssize_t	*width;
	ssize_t	*precision;
	char	*converted;
	char	specifier;
}			t_parameters;

int			ft_printf(const char *format, ...);
char		*ft_apply_specifier(char specifier, va_list ap);
char		*ft_check_flags(char *format, t_flags *flags);
char		*ft_check_mods(char *format, ssize_t *width, ssize_t *precision);
char		*ft_apply_params(t_parameters *params, char *format, va_list ap);
char		*ft_apply_string(char *string);
void		ft_free_params(t_parameters *params);
void		ft_init_params(t_parameters *params);

#endif
