/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:31 by pleander          #+#    #+#             */
/*   Updated: 2024/07/22 14:11:44 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static void	calculate_translation(mlx_t *mlx, t_map *map)
{
	int	x[2];
	int	y[2];
	size_t	col;
	size_t	row;

	x[0] = mlx->width;
	x[1] = 0;
	y[0] = mlx->height;
	y[1] = 0;
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->sc[row][col].x < x[0])
				x[0] = map->sc[row][col].x;
			if (map->sc[row][col].x > x[1])
				x[1] = map->sc[row][col].x;
			if (map->sc[row][col].y < y[0])
				y[0] = map->sc[row][col].y;
			if (map->sc[row][col].y > y[1])
				y[1] = map->sc[row][col].y;
			col++;
		}
		row++;
	}
	map->x_translate = ((mlx->width - (x[1] - x[0])) / 2) - x[0];
	map->y_translate = ((mlx->height - (y[1] - y[0])) / 2) - y[0];
}

static void	apply_translation(t_map *map)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			map->sc[row][col].x += map->x_translate;
			map->sc[row][col].y += map->y_translate;
			col++;
		}
		row++;
	}
}

void draw_map(mlx_t *mlx, t_map *map, mlx_image_t *img)
{
	size_t	i;
	size_t	j;
	int color;
	
	calculate_translation(mlx, map);
	apply_translation(map);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			//color = (0xFFFFFF << map->sc[i][j].color);
			//
			if (j != map->columns - 1)
				draw_line(map->sc[i][j], map->sc[i][j + 1], img);
			if (i != map->rows - 1)
				draw_line(map->sc[i][j], map->sc[i + 1][j], img);
			j++;
		}
		i++;
	}
}

