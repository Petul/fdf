/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:08:48 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:16:36 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_clip_bottom(mlx_image_t *img,
			t_point2d *s, t_point2d *e, int xy[2])
{
	xy[0] = s->x + (e->x - s->x) * ((int)(img->height - 1)
			- s->y) / (e->y - s->y);
	xy[1] = img->height - 1;
}

void	calc_clip_top(t_point2d *s, t_point2d *e, int xy[2])
{
	xy[0] = s->x + (e->x - s->x) * (1 - s->y) / (e->y - s->y);
	xy[1] = 1;
}

void	calc_clip_right(mlx_image_t *img,
			t_point2d *s, t_point2d *e, int xy[2])
{
	xy[1] = s->y + (e->y - s->y) * ((int)(img->width - 1)
			- s->x) / (e->x - s->x);
	xy[0] = img->width - 1;
}

void	calc_clip_left(t_point2d *s, t_point2d *e, int xy[2])
{
	xy[1] = s->y + (e->y - s->y) * (1 - s->x) / (e->x - s->x);
	xy[0] = 1;
}
