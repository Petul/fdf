/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:46 by pleander          #+#    #+#             */
/*   Updated: 2024/07/17 11:54:48 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"
#include <stdio.h>

static int abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	plot_low(t_point start, t_point end, mlx_image_t *img)
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
	while (start.x <= end.x)
	{
		mlx_put_pixel(img, start.x, start.y, start.color);
		if (d > 0)
		{
			start.y = start.y + y_i;
			d = d + (2 * (dy - dx));
		}
		d = d + 2 * dy;
		start.x++;
	}
}

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	plot_high(t_point start, t_point end, mlx_image_t *img)
{
	swap(&start.x, &start.y);
	swap(&end.x, &end.y);
	plot_low(start, end, img);

}

void	draw_line(t_point start, t_point end, mlx_image_t *img)
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
