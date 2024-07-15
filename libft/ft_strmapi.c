/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:49:44 by pleander          #+#    #+#             */
/*   Updated: 2024/04/24 09:49:39 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dup;

	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = f(i, dup[i]);
		i++;
	}
	return (dup);
}
