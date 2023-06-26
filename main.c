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

#include "mandatory/includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft;
	int	stdio;

	ft = ft_printf("%p", NULL);
	printf("\n");
	stdio = printf("%p", NULL);
	printf("\n");
	if (ft == stdio)
		printf("\nSame return values.");
	else
	{
		printf("\ndifference in return values.\n");
		printf("returned: %d\nexpected: %d\n", ft, stdio);
	}
	return (0);
}
