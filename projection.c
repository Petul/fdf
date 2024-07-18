/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:29:43 by pleander          #+#    #+#             */
/*   Updated: 2024/07/18 19:40:15 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "fdf.h"

// static void	get_projection(t_point3d wc, t_point2d *sc)
// {
// 	sc->y = (size_t)floor((wc.x - wc.z) * 1.414);
// 	sc->x = (size_t)floor((wc.x + 2 * wc.y + wc.z) * 0.408);
// 	//sc->x = (size_t)floor((wc.x - wc.y + wc.z) * 0.577);
// }

static void	get_projection(t_point3d wc, t_point2d *sc)
{
	rotate_z(10, &wc);
	rotate_x(35, &wc);
	sc->x = wc.x + 100;
	sc->y = wc.y + 100;
	//sc->x = (size_t)floor((wc.x - wc.y + wc.z) * 0.577);
}

void	calculate_projection(t_map *map)
{
	size_t	row;
	size_t	col;
	size_t	scale;

	scale = WIDTH / (map->columns + 10);
	

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			get_projection(get_3d_point(col, row, map, scale), &map->sc[row][col]);
			col++;
		}
		row++;
	}
}
