/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:56 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 10:49:10 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void reset_map(void	*context)
{
	t_context *c;

	c = (t_context *)context;
	c->map->settings->x_rot = DEFFAULT_X_ROT;
	c->map->settings->y_rot = DEFFAULT_Y_ROT;
	c->map->settings->z_rot = DEFFAULT_Z_ROT;
	c->map->settings->x_offset = 0;
	c->map->settings->y_offset = 0;
	c->map->settings->current_color = 0;
	c->map->settings->thickness = 1;
	calculate_auto_scale(c);
	calculate_projection(c->map);
	calculate_translation(c->map);
}

void	resize_image(t_map *m)
{
	ft_memset(m->img->pixels, 0, m->img->width * m->img->height * sizeof(int32_t));
	calculate_projection(m);
	calculate_translation(m);
	draw_map(m, m->img);
}

void	zoom_image(t_map *m, double ydelta)
{
	if (ydelta > 0)
	{
		m->settings->xy_scale *= 1.1;
		m->settings->z_scale *= 1.1;
	}
	else
	{
		m->settings->xy_scale *= 0.9;
		m->settings->z_scale *= 0.9;
	}
	ft_memset(m->img->pixels, 0, m->img->width * m->img->height * sizeof(int32_t));
	calculate_projection(m);
	calculate_translation(m);
	draw_map(m, m->img);
}
