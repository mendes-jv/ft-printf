/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:35:24 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/25 17:36:52 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/includes/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ft;
	int	stdio;

	ft_printf("ft_printf: ");
	ft = ft_printf("%020.10i", -42000);
	printf("X\n   printf: ");
	stdio = printf("%020.10i", -42000);
	if (ft == stdio)
		printf("X\nSame return values.");
	else
	{
		printf("X\ndifference in return values.\n");
		printf("returned: %d\noriginal: %d\n", ft, stdio);
	}
	return (0);
}
