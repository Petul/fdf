/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:12:52 by pleander          #+#    #+#             */
/*   Updated: 2024/04/25 13:36:01 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;	
	size_t			i;
	size_t			chunksize;
	size_t			qword_value;

	p = (unsigned char *)b;
	chunksize = sizeof(size_t);
	i = 0;
	while (i < chunksize)
	{
		qword_value = (qword_value << 8) | (unsigned char)c;
		i++;
	}
	while (len >= chunksize)
	{
		*(size_t *)p = qword_value;
		p += chunksize;
		len -= chunksize;
	}
	while (len > 0)
	{
		*p = (unsigned char)c;
		len--;
	}
	return (b);
}
