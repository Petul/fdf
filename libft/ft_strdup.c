/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:40:12 by pleander          #+#    #+#             */
/*   Updated: 2024/04/18 15:32:59 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, size);
	return (copy);
}
