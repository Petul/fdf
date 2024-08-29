/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thickness.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:46:58 by pleander          #+#    #+#             */
/*   Updated: 2024/08/29 09:52:57 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	float_abs(float f)
{
	if (f < 0)
		return (-f);
	return (f);
}

static void	thickness_x_dir(t_point2d *s, t_point2d *e, size_t level)
{
	if (level % 2 == 0)
	{
		s->x += level;
		e->x += level;
	}
	else
	{
		s->x -= level;
		e->x -= level;
	}
}

static void	thickness_y_dir(t_point2d *s, t_point2d *e, size_t level)
{
	if (level % 2 == 0)
	{
		s->y += level;
		e->y += level;
	}
	else
	{
		s->y -= level;
		e->y -= level;
	}
}

/**
 * @brief Applies thickness to the line
 *
 * @param s line start
 * @param e line end
 * @param level thickness level
 */
void	apply_thickness(t_point2d *s, t_point2d *e, size_t level)
{
	float	k;

	k = float_abs((e->y - s->y) / (float)(e->x - s->x));
	if (k > 1)
		thickness_x_dir(s, e, level);
	else
		thickness_y_dir(s, e, level);
}
