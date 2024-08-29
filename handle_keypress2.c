/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:36:24 by pleander          #+#    #+#             */
/*   Updated: 2024/08/29 16:25:34 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_model(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_Z)
		c->map->settings->z_scale *= 0.9;
	else if (keydata.key == MLX_KEY_X)
		c->map->settings->z_scale *= 1.1;
}

void	move_model(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_D)
		c->map->settings->x_offset += 2;
	else if (keydata.key == MLX_KEY_A)
		c->map->settings->x_offset -= 2;
	else if (keydata.key == MLX_KEY_W)
		c->map->settings->y_offset += 2;
	else if (keydata.key == MLX_KEY_S)
		c->map->settings->y_offset -= 2;
}

void	reset_model(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_R)
		reset_map(c);
}
