/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:35:18 by pleander          #+#    #+#             */
/*   Updated: 2024/08/14 11:19:55 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	base_index(const char c, const char *base)
{
	char	*c_pos;

	c_pos = ft_strchr(base, c);
	if (!c_pos)
		return (-1);
	return ((int)(c_pos - base));
}

static int	base_valid(const char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	long	res;
	int		sign;

	if (!base_valid(base))
		return (-1);
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	res = 0;
	while (*str && base_index(*str, base) >= 0)
	{
		res = (res * ft_strlen(base)) + sign * base_index(*str, base);
		if (sign == 1 && res < 0)
			return (-1);
		else if (sign == -1 && res > 0)
			return (0);
		str++;
	}
	return ((int)res);
}
