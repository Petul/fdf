/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:30 by pleander          #+#    #+#             */
/*   Updated: 2024/08/20 13:49:05 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft/include/libft.h"
#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

t_point3d	get_3d_point(size_t col, size_t row, t_map *map)
{
	t_point3d	wc;
	size_t		ind;

	if (col > map->columns || row > map->rows)
		error_exit(ERR_STR);
	wc.x = col * map->settings->xy_scale;
	wc.y = row * map->settings->xy_scale;
	ind = row * map->columns + col;
	wc.z = map->vertices[ind].height * map->settings->z_scale;
	wc.color = map->vertices[ind].colors[map->settings->current_color];
	return (wc);
}

void	iter_2darr(char **arr, void (fn)(void *))
{
	size_t	i;
	
	i = 0;
	while (arr[i])
	{
		fn((void *)arr[i]);
		i++;
	}
	fn((void *)arr);
}

/**
 * @brief Calculates the scale of the mesh so that the projected picture
 * will always with in the frame even on its diagonal
 *
 * @param map The map
 */
void	calculate_auto_scale(t_context *c)
{
	float	diag_dist;
	float	horizontal;
	float	vertical;
	
	diag_dist = sqrt((c->map->columns * c->map->columns) + (c->map->rows * c->map->rows));
	horizontal = (c->mlx->width - PADDING) / diag_dist;
	vertical = (c->mlx->height - PADDING) / diag_dist;
	if (horizontal < vertical)
		c->map->settings->xy_scale = horizontal;
	else
		c->map->settings->xy_scale = vertical;
	c->map->settings->z_scale = c->map->settings->xy_scale;
	return ;
}

/**
 * @brief Transforms all characters in a string to uppercase
 *
 * @param str 
 */
void	upper(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
