/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:50:20 by pleander          #+#    #+#             */
/*   Updated: 2024/05/18 16:33:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

static int	free_and_return_false(char *num)
{
	if (num != NULL)
		free(num);
	return (FALSE);
}

t_bool	convert_char(t_fspec *s, int data, t_result *r)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (FALSE);
	str[0] = data;
	if (data == 0)
		if (s->min_field_width > 0)
			s->min_field_width -= 1;
	str = apply_field_width(s, str);
	if (!str)
		return (FALSE);
	if (data == 0 && s->negative_field_width)
		write_char(data, r);
	write_string(str, ft_strlen(str), r);
	if (data == 0 && !s->negative_field_width)
		write_char(data, r);
	return (TRUE);
	free(str);
}

t_bool	convert_string(t_fspec *s, char *data, t_result *r)
{
	char	*str;

	if (data == NULL)
		data = NULL_STR;
	str = ft_calloc(ft_strlen(data) + 1, sizeof(char));
	if (!str)
		return (FALSE);
	ft_memcpy(str, data, ft_strlen(data));
	str = apply_string_precision(s, str);
	if (!str)
		return (free_and_return_false(str));
	str = apply_field_width(s, str);
	if (!str)
		return (free_and_return_false(str));
	write_string(str, ft_strlen(str) + 1, r);
	free(str);
	return (TRUE);
}

t_bool	convert_pointer(t_fspec *s, char *data, t_result *r)
{
	char	*num;

	num = ft_ultoa_base((size_t)data, BASE_HEX_LOWER);
	if (!num)
		return (FALSE);
	s->alternate_form = TRUE;
	num = apply_alternate_hex_form(s, num, "0x");
	if (!num)
		return (FALSE);
	num = apply_field_width(s, num);
	if (!num)
		return (FALSE);
	write_string(num, ft_strlen(num), r);
	free(num);
	return (TRUE);
}

t_bool	convert_decimal(t_fspec *s, int data, t_result *r)
{
	char	*num;

	num = ft_itoa(data);
	if (!num)
		return (FALSE);
	num = apply_precision(s, num);
	if (!num)
		return (FALSE);
	num = apply_plus(s, num);
	if (!num)
		return (FALSE);
	num = apply_space_before_pos(s, num);
	if (!num)
		return (FALSE);
	num = apply_field_width(s, num);
	if (!num)
		return (FALSE);
	write_string(num, ft_strlen(num), r);
	free(num);
	return (TRUE);
}
