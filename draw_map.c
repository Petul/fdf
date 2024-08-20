/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:31 by pleander          #+#    #+#             */
/*   Updated: 2024/08/20 15:54:23 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

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
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (j != map->columns - 1)
				draw_line(map->sc[i][j], map->sc[i][j + 1], map->settings->thickness, img);
			if (i != map->rows - 1)
				draw_line(map->sc[i][j], map->sc[i + 1][j], map->settings->thickness, img);
			j++;
		}
		i++;
	}
}

