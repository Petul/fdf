/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:19:39 by pleander          #+#    #+#             */
/*   Updated: 2024/07/11 16:44:13 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		res = (res * 10) + sign * (*str - '0');
		if (sign == 1 && res < 0)
			return (-1);
		else if (sign == -1 && res > 0)
			return (0);
		str++;
	}
	return ((int)res);
}
