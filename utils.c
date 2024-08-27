/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:30 by pleander          #+#    #+#             */
/*   Updated: 2024/08/24 09:35:52 by pleander         ###   ########.fr       */
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

	if (col > map->model->columns || row > map->model->rows)
		error_exit(ERR_STR);
	wc.x = col * map->settings->xy_scale;
	wc.y = row * map->settings->xy_scale;
	ind = row * map->model->columns + col;
	wc.z = map->model->vertices[ind].height * map->settings->z_scale;
	wc.color = map->model->vertices[ind].colors[map->settings->current_color];
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
void	calculate_auto_scale(t_map *m)
{
	float	diag_dist;
	float	horizontal;
	float	vertical;
	
	diag_dist = sqrt((m->model->columns * m->model->columns) + (m->model->rows * m->model->rows));
	horizontal = (m->img->width - PADDING) / diag_dist;
	vertical = (m->img->height - PADDING) / diag_dist;
	if (horizontal < vertical)
		m->settings->xy_scale = horizontal;
	else
		m->settings->xy_scale = vertical;
	m->settings->z_scale = m->settings->xy_scale;
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

/**
 * @brief Updates values of max/min height values
 *
 * @param m model
 * @param v_i vertice index
 */
void update_max_min(t_model * m, size_t v_i)
{
	if (v_i == 0 || m->vertices[v_i].height > m->max_z)
		m->max_z = m->vertices[v_i].height;
	if (v_i == 0 || m->vertices[v_i].height < m->min_z)
		m->min_z = m->vertices[v_i].height;
}
