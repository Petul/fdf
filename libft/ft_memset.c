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
	size_t			qword_value;

	p = (unsigned char *)b;
	i = 0;
	while (i < sizeof(size_t))
	{
		qword_value = (qword_value << 8) | (unsigned char)c;
		i++;
	}
	while (len >= sizeof(size_t))
	{
		*(size_t *)p = qword_value;
		p += sizeof(size_t);
		len -= sizeof(size_t);
	}
	while (len > 0)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}
