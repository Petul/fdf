/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:39:51 by pleander          #+#    #+#             */
/*   Updated: 2024/04/25 13:40:27 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	n;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	if (dst_len >= dstsize)
		return (src_len + dst_len);
	n = 0;
	while (src[n] && dst_len + n < dstsize - 1)
	{
		dst[dst_len + n] = src[n];
		n++;
	}
	dst[dst_len + n] = '\0';
	return (dst_len + src_len);
}
