/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:49 by pleander          #+#    #+#             */
/*   Updated: 2024/07/18 16:12:54 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"
#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


static void draw_square(size_t x, size_t y, size_t len, int color, mlx_image_t *img)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}

}


static void draw_points(t_map *map, mlx_image_t *img)
{
	size_t	i;
	size_t	j;
	int color;
	
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			//color = (0xFFFFFF << map->sc[i][j].color);
			//
			draw_square(map->sc[i][j].x, map->sc[i][j].y, 5, 0xFFFF0000, img);
			j++;
		}
		i++;
	}
}


// Print the window width and height.
int	fdf(t_map *map)
{
	// MLX allows you to define its core behaviour before startup.
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		error_exit((char *)mlx_strerror(mlx_errno));

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));

	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	calculate_projection(map);
	draw_map(map, img);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}
