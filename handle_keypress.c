/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:07:09 by pleander          #+#    #+#             */
/*   Updated: 2024/08/16 16:09:22 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

void	handle_keypress(mlx_key_data_t keydata, void *context)
{
	t_context	*c;
	
	c = (t_context *)context;
	if (keydata.key == MLX_KEY_H)
		c->map->settings->z_rot -= 1;
	if (keydata.key == MLX_KEY_L)
		c->map->settings->z_rot += 1;
	if (keydata.key == MLX_KEY_J)
		c->map->settings->x_rot += 1;
	if (keydata.key == MLX_KEY_K)
		c->map->settings->x_rot -= 1;
	ft_memset(c->img->pixels, 0, c->img->width * c->img->height * sizeof(int32_t));
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
	draw_map(c->map, c->img);
}
