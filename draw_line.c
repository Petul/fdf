
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:39:46 by pleander          #+#    #+#             */
/*   Updated: 2024/08/28 12:50:06 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "libft/include/libft.h"
#include "fdf.h"

static void	plot_low(t_point2d s, t_point2d e, mlx_image_t *img, int dxdy[2])
{
	int	d;
	int	y_i;
	int	i;

	y_i = 1;
	if (dxdy[1] < 0)
	{
		y_i = -1;
		dxdy[1] = -dxdy[1];
	}
	d = (2 * dxdy[1]) - dxdy[0];
	i = 0;
	while (s.x + i <= e.x)
	{
		mlx_put_pixel(img, (uint32_t)(s.x + i), (uint32_t)s.y, get_rgba(
				interpolate_colors(s.color, e.color, (i / (float)dxdy[0]))));
		if (d > 0)
		{
			s.y = s.y + y_i;
			d = d + (2 * (dxdy[1] - dxdy[0]));
		}
		else
			d = d + (2 * dxdy[1]);
		i++;
	}
}

static void	plot_high(t_point2d s, t_point2d e, mlx_image_t *img, int dxdy[2])
{
	int	d;
	int	x_i;
	int	i;

	x_i = 1;
	if (dxdy[0] < 0)
	{
		x_i = -1;
		dxdy[0] = -dxdy[0];
	}
	d = (2 * dxdy[0]) - dxdy[1];
	i = 0;
	while (s.y + i <= e.y)
	{
		mlx_put_pixel(img, (uint32_t)s.x, (uint32_t)(s.y + i), get_rgba(
				interpolate_colors(s.color, e.color, (i / (float)dxdy[1]))));
		if (d > 0)
		{
			s.x = s.x + x_i;
			d = d + (2 * (dxdy[0] - dxdy[1]));
		}
		else
			d = d + (2 * dxdy[0]);
		i++;
	}
}

static void	draw_low(t_point2d start, t_point2d end, mlx_image_t *img)
{
	int		dxdy[2];

	if (start.x > end.x)
	{
		dxdy[0] = start.x - end.x;
		dxdy[1] = start.y - end.y;
		plot_low(end, start, img, dxdy);
	}
	else
	{
		dxdy[0] = end.x - start.x;
		dxdy[1] = end.y - start.y;
		plot_low(start, end, img, dxdy);
	}
}

static void	draw_high(t_point2d start, t_point2d end, mlx_image_t *img)
{
	int		dxdy[2];

	if (start.y > end.y)
	{
		dxdy[0] = start.x - end.x;
		dxdy[1] = start.y - end.y;
		plot_high(end, start, img, dxdy);
	}
	else
	{
		dxdy[0] = end.x - start.x;
		dxdy[1] = end.y - start.y;
		plot_high(start, end, img, dxdy);
	}
}

void	draw_line(t_point2d start, t_point2d end, size_t thickness,
			mlx_image_t *img)
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
		if (!clip_line(img, &start, &end))
			break ;
		if (ft_abs(end.y - start.y) < ft_abs(end.x - start.x))
			draw_low(start, end, img);
		else
			draw_high(start, end, img);
		i++;
	}
}
