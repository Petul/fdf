/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:56 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:59:20 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/memlist.h"
#include "fdf.h"

/**
 * @brief Initializes the map structure
 *
 * @param mlx 
 * @param model the 3d model structure
 * @return initialized map
 */
t_map	*init_map(mlx_t *mlx, t_model *model)
{
	t_map	*map;
	size_t	i;

	map = reserve(sizeof(t_map));
	if (!map)
		error_exit(ERR_STR);
	map->model = model;
	map->sc = creserve(map->model->rows, sizeof(t_point2d *));
	map->settings = creserve(1, sizeof(t_settings));
	if (!map->sc || !map->settings)
		error_exit(ERR_STR);
	i = 0;
	while (i < map->model->rows)
	{
		map->sc[i] = creserve(model->columns, sizeof(t_point2d));
		if (!map->sc[i])
			error_exit(ERR_STR);
		i++;
	}
	map->img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!map->img || (mlx_image_to_window(mlx, map->img, 0, 0) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));
	return (map);
}

/**
 * @brief Resets the map to default settings
 *
 * @param context 
 */
void	reset_map(void	*context)
{
	t_context	*c;

	c = (t_context *)context;
	c->map->settings->x_rot = DEFFAULT_X_ROT;
	c->map->settings->y_rot = DEFFAULT_Y_ROT;
	c->map->settings->z_rot = DEFFAULT_Z_ROT;
	c->map->settings->x_offset = 0;
	c->map->settings->y_offset = 0;
	c->map->settings->current_color = 0;
	c->map->settings->thickness = 1;
	calculate_auto_scale(c->map);
	calculate_projection(c->map);
	calculate_translation(c->map);
}
