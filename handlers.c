/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:35:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:59:52 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Handles the resize hook
 *
 * @param width 
 * @param height 
 * @param context 
 */
void	handle_resize(int32_t width, int32_t height, void *context)
{
	t_context	*c;

	c = (t_context *)context;
	mlx_resize_image(c->map->img, width, height);
	resize_image(c->map);
}

/**
 * @brief Handles the zoom hook
 *
 * @param xdelta 
 * @param ydelta 
 * @param context 
 */
void	handle_zoom(double xdelta, double ydelta, void *context)
{
	t_context	*c;

	(void)xdelta;
	c = (t_context *)context;
	zoom_image(c->map, ydelta);
}
