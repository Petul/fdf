/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:53:05 by pleander          #+#    #+#             */
/*   Updated: 2024/04/24 09:12:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*sub;

	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_strchr(set, s1[end]) != NULL)
		end--;
	if (start > end)
		sub = ft_substr(s1, start, 0);
	else
		sub = ft_substr(s1, start, end - start + 1);
	if (!sub)
		return (NULL);
	return (sub);
}
