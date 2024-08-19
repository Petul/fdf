/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/16 15:58:48 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// static void draw_square(size_t x, size_t y, size_t len, int color, mlx_image_t *img)
// {
// 	size_t	i;
// 	size_t	j;
//
// 	i = 0;
// 	while (i < len - 1)
// 	{
// 		j = 0;
// 		while (j < len - 1)
// 		{
// 			mlx_put_pixel(img, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
//
// }

static void reset_map(void	*context)
{
	t_context *c;

	c = (t_context *)context;
	c->map->settings->x_rot = DEFFAULT_X_ROT;
	c->map->settings->y_rot = DEFFAULT_Y_ROT;
	c->map->settings->z_rot = DEFFAULT_Z_ROT;
	calculate_auto_scale(context);
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
}

void	handle_resize(int32_t width, int32_t height, void *context)
{
	t_context	*c;
	
	c = (t_context *)context;
	mlx_resize_image(c->img, width, height);
	ft_memset(c->img->pixels, 0, c->img->width * c->img->height * sizeof(int32_t));
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
	draw_map(c->map, c->img);
}

void	handle_zoom(double xdelta, double ydelta, void *context)
{
	t_context *c;

	(void)xdelta;
	c = (t_context *)context;
	if (ydelta > 0)
	{
		c->map->settings->xy_scale *= 1.1;
		c->map->settings->z_scale *= 1.1;
	}
	else
	{
		c->map->settings->xy_scale *= 0.9;
		c->map->settings->z_scale *= 0.9;
	}
	ft_memset(c->img->pixels, 0, c->img->width * c->img->height * sizeof(int32_t));
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
	draw_map(c->map, c->img);
}

// Print the window width and height.
int	fdf(t_context *context)
{
	// MLX allows you to define its core behaviour before startup.
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		error_exit((char *)mlx_strerror(mlx_errno));
	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));

	context->mlx = mlx;
	context->img = img;
	reset_map(context);
	draw_map(context->map, img);
	mlx_resize_hook(mlx, &handle_resize, context);
	mlx_scroll_hook(mlx, &handle_zoom, context);
	mlx_key_hook(mlx, &handle_keypress, context);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
