/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:46 by pleander          #+#    #+#             */
/*   Updated: 2024/07/22 16:36:07 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static int abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	plot_low(t_point2d start, t_point2d end, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	d;
	int	y_i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	y_i = 1;
	if (dy < 0)
	{
		y_i = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while (start.x <= end.x && start.y >= 0 && (uint32_t)start.y <= img->height && start.x >= 0 && (uint32_t)start.x <= img->width)
	{
		mlx_put_pixel(img, start.x, start.y, start.color);
		if (d > 0)
		{
			start.y = start.y + y_i;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		start.x++;
	}
}


static void	plot_high(t_point2d start, t_point2d end, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	d;
	int	x_i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	x_i = 1;
	if (dx < 0)
	{
		x_i = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (start.y <= end.y && start.y >= 0 && (uint32_t)start.y <= img->height && start.x >= 0 && (uint32_t)start.x <= img->width)
	{
		mlx_put_pixel(img, start.x, start.y, start.color);
		if (d > 0)
		{
			start.x = start.x + x_i;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + (2 * dx);
		start.y++;
	}
}

void	draw_line(t_point2d start, t_point2d end, mlx_image_t *img)
{
	if (abs(end.y - start.y) < abs(end.x - start.x))
	{
		if (start.x > end.x)
			plot_low(end, start, img);
		else
			plot_low(start, end, img);
	}
	else
	{
		if (start.y > end.y)
			plot_high(end, start, img);
		else
			plot_high(start, end, img);
	}
}
