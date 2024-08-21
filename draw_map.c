/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:31 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 12:48:16 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static void	apply_translation(t_map *map)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (row < map->model->rows)
	{
		col = 0;
		while (col < map->model->columns)
		{
			map->sc[row][col].x += map->settings->x_trans;
			map->sc[row][col].y += map->settings->y_trans;
			col++;
		}
		row++;
	}
}

void draw_map(t_map *map, mlx_image_t *img)
{
	size_t	i;
	size_t	j;
	
	apply_translation(map);
	i = 0;
	while (i < map->model->rows)
	{
		j = 0;
		while (j < map->model->columns)
		{
			if (j != map->model->columns - 1)
				draw_line(map->sc[i][j], map->sc[i][j + 1], map->settings->thickness, img);
			if (i != map->model->rows - 1)
				draw_line(map->sc[i][j], map->sc[i + 1][j], map->settings->thickness, img);
			j++;
		}
		i++;
	}
}

void	resize_image(t_map *m)
{
	ft_memset(m->img->pixels, 0, m->img->width * m->img->height * sizeof(int32_t));
	calculate_projection(m);
	calculate_translation(m);
	draw_map(m, m->img);
}

void	zoom_image(t_map *m, double ydelta)
{
	if (ydelta > 0)
	{
		m->settings->xy_scale *= 1.1;
		m->settings->z_scale *= 1.1;
	}
	else
	{
		m->settings->xy_scale *= 0.9;
		m->settings->z_scale *= 0.9;
	}
	ft_memset(m->img->pixels, 0, m->img->width * m->img->height * sizeof(int32_t));
	calculate_projection(m);
	calculate_translation(m);
	draw_map(m, m->img);
}

