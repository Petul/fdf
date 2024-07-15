/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:43:42 by pleander          #+#    #+#             */
/*   Updated: 2024/05/18 16:52:45 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

t_bool	convert_unsigned(t_fspec *s, unsigned int data, t_result *r)
{
	char	*num;

	num = ft_utoa_base(data, BASE_DEC);
	if (!num)
		return (FALSE);
	num = apply_precision(s, num);
	if (!num)
		return (FALSE);
	num = apply_field_width(s, num);
	if (!num)
		return (FALSE);
	write_string(num, ft_strlen(num), r);
	free(num);
	return (TRUE);
}

static char	*convert_hex(t_fspec *s, int data, char *base)
{
	char	*num;

	num = ft_utoa_base(data, base);
	if (!num)
		return (NULL);
	if (s->alternate_form && (!only_zero_or_space(num)))
	{
		if (s->min_field_width < 2)
			s->min_field_width = 0;
		else
			s->min_field_width -= 2;
	}
	num = apply_precision(s, num);
	if (!num)
		return (NULL);
	num = apply_field_width(s, num);
	if (!num)
		return (NULL);
	return (num);
}

t_bool	convert_hex_upper(t_fspec *s, int data, t_result *r)
{
	char	*num;

	num = convert_hex(s, data, BASE_HEX_UPPER);
	if (!num)
		return (FALSE);
	if (!only_zero_or_space(num))
	{
		num = apply_alternate_hex_form(s, num, "0X");
		if (!num)
			return (FALSE);
	}
	write_string(num, ft_strlen(num), r);
	free(num);
	return (TRUE);
}

t_bool	convert_hex_lower(t_fspec *s, int data, t_result *r)
{
	char	*num;

	num = convert_hex(s, data, BASE_HEX_LOWER);
	if (!num)
		return (FALSE);
	if (!only_zero_or_space(num))
	{
		num = apply_alternate_hex_form(s, num, "0x");
		if (!num)
			return (FALSE);
	}
	write_string(num, ft_strlen(num), r);
	free(num);
	return (TRUE);
}
