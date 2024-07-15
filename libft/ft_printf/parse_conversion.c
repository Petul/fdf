/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:42:40 by pleander          #+#    #+#             */
/*   Updated: 2024/05/23 11:43:11 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/ft_printf.h"
#include "../include/libft.h"

static t_bool	set_field_width(t_fspec *s, char *conversion);
static t_bool	set_precision(t_fspec *s, char *conversion);
static t_bool	get_zero_padding(char *conversion);
static void		*free_and_return_null(t_fspec *s);

t_fspec	*parse_conversion(char *conversion)
{
	t_fspec	*s;

	s = malloc(sizeof(t_fspec));
	if (!s)
		return (NULL);
	ft_bzero(s, sizeof(t_fspec));
	if (ft_strchr(conversion, '#'))
		s->alternate_form = TRUE;
	if (ft_strchr(conversion, '0'))
		s->zero_padding = get_zero_padding(conversion);
	if (ft_strchr(conversion, '-'))
		s->negative_field_width = TRUE;
	if (ft_strchr(conversion, ' '))
		s->space_before_pos = TRUE;
	if (ft_strchr(conversion, '+'))
		s->plus_before_pos = TRUE;
	if (ft_strchr(conversion, '.'))
		s->has_dot = TRUE;
	if (set_field_width(s, conversion) == FALSE)
		return (free_and_return_null(s));
	if (set_precision(s, conversion) == FALSE)
		return (free_and_return_null(s));
	return (s);
}

static void	*free_and_return_null(t_fspec *s)
{
	free(s);
	return (NULL);
}

static t_bool	set_field_width(t_fspec *s, char *conversion)
{
	size_t	i;
	size_t	j;
	size_t	num;
	char	*numstr;

	i = 0;
	j = 0;
	while (conversion[i] && conversion[i] != '.')
	{
		if (ft_strchr("123456789", conversion[i]))
		{
			while (i + j < ft_strlen(conversion)
				&& ft_strchr("0123456789", conversion[i + j]))
				j++;
			numstr = ft_substr(conversion, i, j);
			if (!numstr)
				return (FALSE);
			num = ft_atoi(numstr);
			free(numstr);
			s->min_field_width = num;
			return (TRUE);
		}
		i++;
	}
	return (TRUE);
}

static t_bool	set_precision(t_fspec *s, char *conversion)
{
	char	*dot;
	char	*numstr;
	size_t	i;
	size_t	num;

	dot = ft_strchr(conversion, '.');
	if (!dot)
		return (TRUE);
	i = 0;
	while (ft_isdigit(dot[i + 1]))
		i++;
	if (!i)
		return (TRUE);
	numstr = ft_substr(dot, 1, i);
	if (!numstr)
		return (FALSE);
	num = ft_atoi(numstr);
	free(numstr);
	s->precision = num;
	return (TRUE);
}

static t_bool	get_zero_padding(char *conversion)
{
	while (*conversion)
	{
		if (ft_isdigit(*conversion))
		{
			if (*conversion == '0')
				return (TRUE);
			return (FALSE);
		}
		conversion++;
	}
	return (FALSE);
}
