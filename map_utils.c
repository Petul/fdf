/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:00:56 by pleander          #+#    #+#             */
/*   Updated: 2024/08/20 15:53:38 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void reset_map(void	*context)
{
	t_context *c;

	c = (t_context *)context;
	c->map->settings->x_rot = DEFFAULT_X_ROT;
	c->map->settings->y_rot = DEFFAULT_Y_ROT;
	c->map->settings->z_rot = DEFFAULT_Z_ROT;
	c->map->settings->x_offset = 0;
	c->map->settings->y_offset = 0;
	c->map->settings->current_color = 0;
	c->map->settings->thickness = 1;
	calculate_auto_scale(context);
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
}
