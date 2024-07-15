/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:45:50 by pleander          #+#    #+#             */
/*   Updated: 2024/04/25 13:50:07 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "include/libft.h"

static int	count_splits(char const *s, char c)
{
	int	count;
	int	len;
	int	i;

	count = 0;
	i = 0;
	len = (int)ft_strlen(s);
	if (len == 0)
		return (0);
	if (s[i] != c && i == 0)
		count++;
	while (i < len - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static void	free_array(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
}

static int	do_splitting(char **splits, char *trimmed, char c, int n_splits)
{
	int	start;
	int	end;
	int	i;

	end = 0;
	i = 0;
	start = end;
	while (n_splits - i > 0)
	{
		if (trimmed[end] == c || (trimmed[end] == 0))
		{
			splits[i] = ft_substr(trimmed, start, end - start);
			if (splits[i] == NULL)
			{
				free_array(splits);
				return (0);
			}
			i++;
			while (end < (int)ft_strlen(trimmed) && trimmed[end] == c)
				end++;
			start = end;
		}
		end++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	char	*trimmed;
	int		n_splits;
	char	set[2];

	set[0] = c;
	set[1] = 0;
	trimmed = ft_strtrim(s, set);
	if (!trimmed)
		return (NULL);
	n_splits = count_splits(trimmed, c);
	splits = ft_calloc(n_splits + 1, sizeof(char *));
	if (!splits)
	{
		free(trimmed);
		return (NULL);
	}
	if (!do_splitting(splits, trimmed, c, n_splits))
	{
		free(splits);
		splits = NULL;
	}
	free(trimmed);
	return (splits);
}
