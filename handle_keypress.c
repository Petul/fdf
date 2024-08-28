/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:07:09 by pleander          #+#    #+#             */
/*   Updated: 2024/08/28 12:44:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

static void	cycle_color(t_map *map)
{
	if (map->settings->current_color >= N_COLORS - 1)
		map->settings->current_color = 0;
	else
		map->settings->current_color++;
}

static void	cycle_model_color(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		cycle_color(c->map);
}

static void	update_thickness(int change, t_map *map)
{
	if (map->settings->thickness + change < 1)
		map->settings->thickness = 1;
	else if (map->settings->thickness + change > 10)
		map->settings->thickness = 10;
	else
		map->settings->thickness += change;
}

static void	update_model_thickness(mlx_key_data_t keydata, t_context *c)
{
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		update_thickness(-1, c->map);
	else if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		update_thickness(1, c->map);
}

void	handle_keypress(mlx_key_data_t keydata, void *context)
{
	t_context	*c;

	c = (t_context *)context;
	rotate_model(keydata, c);
	zoom_model(keydata, c);
	move_model(keydata, c);
	update_model_thickness(keydata, c);
	cycle_model_color(keydata, c);
	reset_model(keydata, c);
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(c->mlx);
		return ;
	}
	ft_memset(c->map->img->pixels, 0,
		c->map->img->width * c->map->img->height * sizeof(int32_t));
	calculate_projection(c->map);
	calculate_translation(c->map);
	draw_map(c->map, c->map->img);
}
