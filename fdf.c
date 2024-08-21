/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:14 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

// Print the window width and height.
int	fdf(t_context *c)
{
	// MLX allows you to define its core behaviour before startup.
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		error_exit((char *)mlx_strerror(mlx_errno));
	c->mlx = mlx;

	// Create and display the map image.
	mlx_image_t* map_img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!map_img || (mlx_image_to_window(mlx, map_img, 0, 0) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));
	c->map->img = map_img;

	mlx_image_t*	menu_img = mlx_new_image(mlx, 100, 300);
	if (!menu_img || (mlx_image_to_window(mlx, menu_img, 10, 10) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));
	c->menu->img = menu_img;

	reset_map(c);
	draw_map(c->map, map_img);
	draw_menu(c->menu);
	mlx_resize_hook(mlx, &handle_resize, c);
	mlx_scroll_hook(mlx, &handle_zoom, c);
	mlx_key_hook(mlx, &handle_keypress, c);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
