/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:01:07 by pleander          #+#    #+#             */
/*   Updated: 2024/04/25 13:29:04 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdint.h>
#include "include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (count != 0)
	{
		if (size > SIZE_MAX / count)
			return (NULL);
	}
	alloc = malloc(count * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, count * size);
	return (alloc);
}
