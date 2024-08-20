/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:07:09 by pleander          #+#    #+#             */
/*   Updated: 2024/08/20 14:16:45 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static	void cycle_color(t_map *map)
{
	if (map->settings->current_color >= N_COLORS - 1)
		map->settings->current_color = 0;
	else
		map->settings->current_color++;

}
static	void update_degrees(int *s, int c)
{
	*s += c;
	if (*s >= 360)
		*s -= 360;
	if (*s < 0)
		*s += 360;
}
//todo: scale the values maybe
void	handle_keypress(mlx_key_data_t keydata, void *context)
{
	t_context	*c;
	
	c = (t_context *)context;
	if (keydata.key == MLX_KEY_H)
		update_degrees(&c->map->settings->z_rot, -1);
	if (keydata.key == MLX_KEY_L)
		update_degrees(&c->map->settings->z_rot, 1);
	if (keydata.key == MLX_KEY_J)
		update_degrees(&c->map->settings->x_rot, 1);
	if (keydata.key == MLX_KEY_K)
		update_degrees(&c->map->settings->x_rot, -1);
	if (keydata.key == MLX_KEY_Z)
		c->map->settings->z_scale *= 0.9;
	if (keydata.key == MLX_KEY_X)
		c->map->settings->z_scale *= 1.1;
	if (keydata.key == MLX_KEY_D)
		c->map->settings->x_offset += 2;
	if (keydata.key == MLX_KEY_A)
		c->map->settings->x_offset -= 2;
	if (keydata.key == MLX_KEY_W)
		c->map->settings->y_offset += 2;
	if (keydata.key == MLX_KEY_S)
		c->map->settings->y_offset -= 2;
	if (keydata.key == MLX_KEY_R)
		reset_map(c);	
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		cycle_color(c->map);
	ft_memset(c->img->pixels, 0, c->img->width * c->img->height * sizeof(int32_t));
	calculate_projection(c->map);
	calculate_translation(c->mlx, c->map);
	draw_map(c->map, c->img);
}
