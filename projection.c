/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:29:43 by pleander          #+#    #+#             */
/*   Updated: 2024/08/15 14:29:47 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_projection(t_point3d wc, t_point2d *sc, t_map *map)
{
	rotate_z(map->settings->z_rot, &wc);
	rotate_x(map->settings->x_rot, &wc);
	rotate_y(map->settings->y_rot, &wc);
	sc->x = wc.x;
	sc->y = wc.y;
	sc->color = wc.color;
}

void	calculate_projection(t_map *map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			get_projection(get_3d_point(col, row, map), &map->sc[row][col], map);
			col++;
		}
		row++;
	}
}
