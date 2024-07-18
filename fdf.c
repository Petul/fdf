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

static void quick_draw_line(size_t s_x, size_t s_y, size_t e_x, size_t e_y, mlx_image_t *img)
{
	t_point2d s;
	t_point2d e;

	s.x = s_x;
	s.y = s_y;
	s.color = 0;
	e.x = e_x;
	e.y = e_y;
	e.color = 0;
	draw_line(s, e, img);

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
	/* Do stuff */

	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	calculate_projection(map);
	draw_map(map, img);
	//draw_points(map, img);
	// draw_square(100, 10, 4, 0, img);
	// draw_square(50, 150, 4, 0, img);
	// quick_draw_line(100, 10, 50, 150, img);
	//
	// draw_square(10, 10, 4, 0, img);
	// draw_square(500, 100, 4, 0, img);
	// quick_draw_line(10, 10, 500, 100, img);
	// quick_draw_line(10, 50, 100, 100, img);
	// quick_draw_line(0, 100, 100, 100, img);
	// quick_draw_line(512, 200, 0, 200, img);
	// quick_draw_line(201, 0, 0, 200, img);
	// quick_draw_line(510, 10, 10, 200, img);
	

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (0);
}
