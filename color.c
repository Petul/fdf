/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:03:48 by pleander          #+#    #+#             */
/*   Updated: 2024/08/15 13:27:41 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_rgba(t_color c)
{
	return (c.r << 24 | c.g << 16 | c.b << 8 | c.a);
}

t_color	get_color(uint32_t rgba)
{
	t_color c;

	c.r = (rgba >> 24) & 0xFF;
	c.g = (rgba >> 16) & 0xFF;
	c.b = (rgba >> 8) & 0xFF;
	c.a = rgba & 0xFF;
	return (c);
}
