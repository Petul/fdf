/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poundsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:17:43 by pleander          #+#    #+#             */
/*   Updated: 2024/05/23 11:43:16 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

static void	*free_and_return_null(void *d1, void *d2)
{
	if (d1 != NULL)
		free(d1);
	if (d2 != NULL)
		free(d2);
	return (NULL);
}

static t_bool	char_in_hex_set(char c)
{
	if (ft_strchr(BASE_HEX_LOWER, c)
		|| ft_strchr(BASE_HEX_UPPER, c))
		return (TRUE);
	return (FALSE);
}

char	*apply_alternate_hex_form(t_fspec *s, char *num, char *pre_str)
{
	size_t	i;
	char	*sub1;
	char	*sub2;
	char	*new_num;

	if (s->alternate_form == FALSE)
		return (num);
	i = 0;
	while (num[i] && !char_in_hex_set(num[i]))
		i++;
	sub1 = ft_substr(num, 0, i);
	if (!sub1)
		return (free_and_return_null(num, NULL));
	sub2 = ft_substr(num, i, ft_strlen(num) - i);
	if (!sub2)
		return (free_and_return_null(sub1, num));
	new_num = ft_strjoin(sub1, pre_str);
	free(sub1);
	if (!new_num)
		return (free_and_return_null(num, sub2));
	free(num);
	num = ft_strjoin(new_num, sub2);
	free(new_num);
	free(sub2);
	return (num);
}
