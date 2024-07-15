/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:35:21 by pleander          #+#    #+#             */
/*   Updated: 2024/05/23 11:43:19 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	convert(size_t n, char *str, char *base)
{
	char	c;

	if (n > (ft_strlen(base) - 1))
		convert(n / ft_strlen(base), str, base);
	c = base[(n % ft_strlen(base))];
	str[ft_strlen(str)] = c;
}

static size_t	count(size_t n, char *base)
{
	size_t	c;

	c = 1;
	while (n > (size_t)ft_strlen(base) - 1)
	{
		c++;
		n = n / ft_strlen(base);
	}
	return (c);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	char	*str;
	size_t	size;

	size = count(n, base) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	convert(n, str, base);
	return (str);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*str;
	size_t	size;

	size = count(n, base) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	convert(n, str, base);
	return (str);
}
