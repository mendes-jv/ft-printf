/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:59:26 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/21 01:59:43 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		delimiter_count(char const *s, char c);
static char		**ft_insertstr(char **arr, char *str, char c, size_t delimiter);
static size_t	ft_substrlen(char *start, char c);

char	**ft_split(char const *s, char c)
{
	size_t	delimiter;
	char	*string;
	char	**array;

	string = ft_strtrim(s, &c);
	if (!string)
		return (NULL);
	if (!*string)
	{
		free(string);
		return (ft_calloc(1, sizeof(char *)));
	}
	delimiter = delimiter_count(string, c);
	array = ft_calloc(delimiter + 1, sizeof(char *));
	array = ft_insertstr(array, string, c, delimiter);
	free(string);
	return (array);
}

static int	delimiter_count(char const *s, char c)
{
	size_t	counter;
	size_t	index;

	counter = 1;
	index = 0;
	while (s[index])
		if (s[index++] == c && s[index] != c)
			counter++;
	return (counter);
}

static char	**ft_insertstr(char **arr, char *str, char c, size_t delimiter)
{
	size_t	index;

	index = 0;
	while (delimiter--)
	{
		arr[index++] = ft_substr(str, 0, ft_substrlen(str, c));
		if (ft_strchr(str, c) != NULL)
			str = ft_strchr(str, c);
		while (*str == c && *str)
			str++;
	}
	return (arr);
}

static size_t	ft_substrlen(char *start, char c)
{
	size_t	counter;

	counter = 0;
	while (*start != c && *start++)
		counter++;
	return (counter);
}
