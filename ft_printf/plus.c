/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:58:17 by pleander          #+#    #+#             */
/*   Updated: 2024/05/23 11:43:16 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/ft_printf.h"

char	*apply_plus(t_fspec *s, char *num)
{
	char	*new_num;

	if ((!s->plus_before_pos) || ft_strchr(num, '-'))
		return (num);
	new_num = ft_strjoin("+", num);
	free(num);
	if (!new_num)
		return (NULL);
	return (new_num);
}
