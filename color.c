/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:03:48 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 12:29:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_rgba(t_color c)
{
	return (c.r << 24 | c.g << 16 | c.b << 8 | c.a);
}

t_color	get_color(uint32_t rgba)
{
	t_color	c;

	c.r = (rgba >> 24) & 0xFF;
	c.g = (rgba >> 16) & 0xFF;
	c.b = (rgba >> 8) & 0xFF;
	c.a = rgba & 0xFF;
	return (c);
}

/**
 * @brief Generates an intermediary color between start and end
 *
 * @param start Start color
 * @param end End color
 * @param d Distance progressed between start and end
 * (e.g. 0.5 is halfway, 0 is at start)
 * @return Intermediary color
 */
t_color	interpolate_colors(t_color start, t_color end, float d)
{
	t_color	in;

	in.r = start.r + (end.r - start.r) * d;
	in.g = start.g + (end.g - start.g) * d;
	in.b = start.b + (end.b - start.b) * d;
	in.a = start.a + (end.a - start.a) * d;
	return (in);
}

/**
 * @brief Cretes color variants for the vertices
 *
 * @param m 
 */
void	paint_vertices(t_model *m)
{
	uint32_t	start;
	uint32_t	end;
	size_t		i;
	size_t		j;
	float		d;

	i = 0;
	while (i < m->columns * m->rows)
	{
		j = 1;
		while (j < N_COLORS)
		{
			d = (float)m->vertices[i].height / (m->max_z - m->min_z);
			start = (0xFFFFFFFF & ~(0xFF << (32 / N_COLORS * (j)))) | 0xFF;
			end = (0x000000FF << (32 / N_COLORS * (j - 1))) | 0xFF;
			m->vertices[i].colors[j] = interpolate_colors(get_color(start),
					get_color(end), d);
			j++;
		}
		i++;
	}
}
