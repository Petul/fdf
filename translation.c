/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:33:55 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:25:43 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Finds middle point of the map and places it in the middle of the
 * image
 *
 * @param map the map
 */
void	calculate_translation(t_map *map)
{
	t_point2d	middle_point;

	middle_point = map->sc[map->model->rows / 2][map->model->columns / 2];
	map->settings->x_trans = (map->img->width / 2) - middle_point.x
		+ map->settings->x_offset;
	map->settings->y_trans = (map->img->height / 2) - middle_point.y
		- map->settings->y_offset;
}
