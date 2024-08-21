/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 12:38:32 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "libft/include/memlist.h"
#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

int	fdf(char *path)
{
	t_context	*c;
	t_model		*model;

	model = read_model(path);
	c = creserve(1, sizeof(t_context));
	if (!c)
		error_exit(ERR_STR);
	// MLX allows you to define its core behaviour before startup.
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		error_exit((char *)mlx_strerror(mlx_errno));
	c->mlx = mlx;

	// Create and display the map image.
	c->map = init_map(mlx, model);
	c->menu = init_menu(mlx);
	reset_map(c);
	draw_map(c->map, c->map->img);
	draw_menu(c->menu);
	mlx_resize_hook(mlx, &handle_resize, c);
	mlx_scroll_hook(mlx, &handle_zoom, c);
	mlx_key_hook(mlx, &handle_keypress, c);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
