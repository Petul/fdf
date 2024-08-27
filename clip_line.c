/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:49:24 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:14:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static int	compute_outcode(mlx_image_t *img, t_point2d *p)
{
	int	oc;

	oc = OC_INSIDE;
	if (p->x < 1)
		oc |= OC_LEFT;
	if (p->x > (int)(img->width - 1))
		oc |= OC_RIGHT;
	if (p->y < 1)
		oc |= OC_TOP;
	if (p->y > (int)(img->height - 1))
		oc |= OC_BOTTOM;
	return (oc);
}

static void	update_xy(mlx_image_t *img, int *xy, int *ocode, t_point2d *p)
{
	p->x = xy[0];
	p->y = xy[1];
	*ocode = compute_outcode(img, p);
}

static int	cohen_sutherland(mlx_image_t *img,
	int oc[2], t_point2d *s, t_point2d *e)
{
	int	oc_update;
	int	xy[2];

	while ((oc[0] | oc[1]))
	{
		if (oc[0] & oc[1])
			return (0);
		if (oc[0] > oc[1])
			oc_update = oc[0];
		else
			oc_update = oc[1];
		if (oc_update & OC_BOTTOM)
			calc_clip_bottom(img, s, e, xy);
		else if (oc_update & OC_TOP)
			calc_clip_top(s, e, xy);
		else if (oc_update & OC_RIGHT)
			calc_clip_right(img, s, e, xy);
		else if (oc_update & OC_LEFT)
			calc_clip_left(s, e, xy);
		if (oc_update == oc[0])
			update_xy(img, xy, &oc[0], s);
		else
			update_xy(img, xy, &oc[1], e);
	}
	return (1);
}

int	clip_line(mlx_image_t *img, t_point2d *start, t_point2d *end)
{
	int	ocode[2];
	int	res;

	ocode[0] = compute_outcode(img, start);
	ocode[1] = compute_outcode(img, end);
	res = cohen_sutherland(img, ocode, start, end);
	return (res);
}
