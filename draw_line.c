/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:46 by pleander          #+#    #+#             */
/*   Updated: 2024/08/20 15:59:21 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	y_i = 1;
	if (dy < 0)
	{
		y_i = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	i = 0;
	while (start.x + i <= end.x)
	{
		if (start.x + i > 0 && start.y > 0 && start.x + i < (int)img->width && start.y < (int)img->height)
			mlx_put_pixel(img, (uint32_t)(start.x + i), (uint32_t)start.y, get_rgba(interpolate_colors(start.color, end.color, (float)(i / (float)dx))));
		if (d > 0)
		{
			start.y = start.y + y_i;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		i++;
	}
}


static void	plot_high(t_point2d start, t_point2d end, mlx_image_t *img)
{
	int	dx;
	int	dy;
	int	d;
	int	x_i;
	int i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	x_i = 1;
	if (dx < 0)
	{
		x_i = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	i = 0;
	while (start.y + i <= end.y)
	{
		if (start.x > 0 && start.y + i > 0 && start.x < (int)img->width && start.y + i < (int)img->height)
			mlx_put_pixel(img, (uint32_t)start.x, (uint32_t)(start.y + i), get_rgba(interpolate_colors(start.color, end.color, (float)(i / (float)dy))));
		if (d > 0)
		{
			start.x = start.x + x_i;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + (2 * dx);
		i++;
	}
}

void	draw_line(t_point2d start, t_point2d end, size_t thickness, mlx_image_t *img)
{
	size_t	i;

	i = 0;
	while (i < thickness)
	{
		if (i % 2 == 0)
		{
			start.x += i;
			end.x += i;
		}
		else
		{
			start.x -= i;
			end.x -= i;
		}
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
		i++;
	}
}
