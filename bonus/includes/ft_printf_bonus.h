/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:30:06 by jovicto2          #+#    #+#             */
/*   Updated: 2023/07/22 23:29:12 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../../libft/includes/libft.h"
# include <stdarg.h>
# icnlude <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef PRINTF_ERROR
#  define PRINTF_ERROR -1
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

# ifndef NOT_SPEC
#  define NOT_SPEC -1
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
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

typedef struct s_flags
{
	bool	has_minus;
	bool	has_plus;
	bool	has_space;
	bool	has_zero;
	bool	has_hashtag;
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
char		*ft_apply_params(t_parameters *params, char *format, va_list ap);
char		*ft_check_flags(char *format, t_flags *flags);
char		*ft_check_mods(char *format, ssize_t *width, ssize_t *precision);
void		ft_init_params(t_parameters *params);
void		ft_free_params(t_parameters *params);
size_t		ft_write_params(t_parameters *params);
ssize_t		ft_apply_width(t_parameters *params, ssize_t *conv_len,
				long *index, size_t *pb);
void		ft_apply_precision(t_parameters *params, ssize_t *conv_len,
				long *index, size_t *pb);
void		ft_apply_conversion(t_parameters *params, ssize_t *conv_len,
				size_t *pb);
void		ft_apply_zero_flag(t_parameters *params, ssize_t *conv_len,
				long *index, size_t *pb);
void		ft_apply_prefixes(t_parameters *params, size_t *pb);

#endif
