/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:45:50 by pleander          #+#    #+#             */
/*   Updated: 2024/05/23 11:45:52 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

void	float_sign(char *num)
{
	char	*sign;
	char	*zero;
	char	sign_character;

	if (ft_strchr(num, '-'))
		sign_character = '-';
	else if (ft_strchr(num, '+'))
		sign_character = '+';
	else
		return ;
	sign = ft_strchr(num, sign_character);
	zero = ft_strchr(num, '0');
	if (!zero || sign < zero)
		return ;
	*zero = sign_character;
	*sign = '0';
}

void	float_space(char *num)
{
	char	*space;
	char	*zero;

	space = ft_strchr(num, ' ');
	zero = ft_strchr(num, '0');
	if (!zero || space < zero)
		return ;
	*zero = ' ';
	*space = '0';
}

int	only_zero_or_space(char *num)
{
	while (*num)
	{
		if (*num != ' ')
			if (*num != '0')
				return (0);
		num++;
	}
	return (1);
}

void	init_t_result(char *output, size_t buf_size, t_result *res)
{
	res->buffer = output;
	res->buf_size = buf_size;
	res->written = 0;
}
