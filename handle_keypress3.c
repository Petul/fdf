/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:12:07 by pleander          #+#    #+#             */
/*   Updated: 2024/08/29 16:31:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

void	change_projection(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_P)
	{
		c->map->settings->proj = PAR;
		c->map->settings->z_rot = 0;
		c->map->settings->x_rot = -90;
	}
	else if (keydata.key == MLX_KEY_I)
	{
		c->map->settings->proj = ISO;
		c->map->settings->z_rot = DEFFAULT_Z_ROT;
		c->map->settings->x_rot = DEFFAULT_X_ROT;
	}
}

static void	update_degrees(float *s, int c)
{
	*s += c;
	if (*s >= 360)
		*s -= 360;
	if (*s < 0)
		*s += 360;
}

void	rotate_model(mlx_key_data_t keydata, t_context *c)
{
	if (c->map->settings->proj == PAR)
	{
		if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
			update_degrees(&c->map->settings->z_rot, -90);
		else if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
			update_degrees(&c->map->settings->z_rot, 90);
		else if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
			update_degrees(&c->map->settings->x_rot, 90);
		else if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
			update_degrees(&c->map->settings->x_rot, -90);
	}
	else
	{
		if (keydata.key == MLX_KEY_H)
			update_degrees(&c->map->settings->z_rot, -1);
		else if (keydata.key == MLX_KEY_L)
			update_degrees(&c->map->settings->z_rot, 1);
		else if (keydata.key == MLX_KEY_J)
			update_degrees(&c->map->settings->x_rot, 1);
		else if (keydata.key == MLX_KEY_K)
			update_degrees(&c->map->settings->x_rot, -1);
	}
}
