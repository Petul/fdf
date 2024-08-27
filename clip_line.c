/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:49:24 by pleander          #+#    #+#             */
/*   Updated: 2024/08/26 15:38:47 by pleander         ###   ########.fr       */
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

static int cohen_sutherland(mlx_image_t *img, int ocode[2], t_point2d *start, t_point2d *end)
{
	int	ocode_update;
	int	x;
	int	y;

	//Loop until start and end inside viewport
	while ((ocode[0] | ocode[1]))
	{
		if (ocode[0] & ocode[1]) // Line will not pass through viewport
			return (0);
		// Calculate point on intersection from a point outside the viewport
		if (ocode[0] > ocode[1])
			ocode_update = ocode[0];
		else
			ocode_update = ocode[1];
		if (ocode_update & OC_BOTTOM)
		{
			x = start->x + (end->x - start->x) * ((int)(img->height - 1) - start->y) / (end->y - start->y);
			y = img->height - 1;
		}
		else if (ocode_update & OC_TOP)
		{
			x = start->x + (end->x - start->x) * (1 - start->y) / (end->y - start->y);
			y = 1;
		}
		else if (ocode_update & OC_RIGHT)
		{
			y = start->y + (end->y - start->y) * ((int)(img->width - 1) - start->x) / (end->x - start->x);
			x = img->width - 1;
		}
		else if (ocode_update & OC_LEFT)
		{
			y = start->y + (end->y - start->y) * (1 - start->x) / (end->x - start->x);
			x = 1;
		}
		if (ocode_update == ocode[0])
		{
			start->x = x;
			start->y = y;
			ocode[0] = compute_outcode(img, start);
		}
		else
		{
			end->x = x;
			end->y = y;
			ocode[1] = compute_outcode(img, end);
		}
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
