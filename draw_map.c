/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:08:31 by pleander          #+#    #+#             */
/*   Updated: 2024/07/18 14:45:42 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

void draw_map(t_map *map, mlx_image_t *img)
{
	size_t	i;
	size_t	j;
	int color;
	
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			//color = (0xFFFFFF << map->sc[i][j].color);
			//
			if (j != map->columns - 1)
				draw_line(map->sc[i][j], map->sc[i][j + 1], img);
			if (i != map->rows - 1)
				draw_line(map->sc[i][j], map->sc[i + 1][j], img);
			j++;
		}
		i++;
	}

}

