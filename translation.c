/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:33:55 by pleander          #+#    #+#             */
/*   Updated: 2024/08/16 15:34:20 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_translation(mlx_t *mlx, t_map *map)
{
	int		x[2];
	int		y[2];
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
	map->settings->x_trans = ((mlx->width - (x[1] - x[0])) / 2) - x[0];
	map->settings->y_trans = ((mlx->height - (y[1] - y[0])) / 2) - y[0];
}
