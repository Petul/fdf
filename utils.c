/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:30 by pleander          #+#    #+#             */
/*   Updated: 2024/07/18 15:26:30 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"
#include "fdf.h"

t_point3d	get_3d_point(size_t col, size_t row, t_map *map, size_t scale)
{
	t_point3d	wc;
	size_t		ind;

	if (col > map->columns || row > map->rows)
		error_exit(ERR_STR);
	wc.x = col * scale;
	wc.y = row * scale;
	ind = row * map->columns + col;
	wc.z = map->vertices[ind].height * scale;
	wc.color = map->vertices[ind].color;
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

// void print_map(t_map *map)
// {
// 	int i = 0;
//
// 	while (i < map->rows * map->columns)
// 	{
// 		ft_printf("%2d ", map->vertices[i].height);
// 		if ((i + 1) % map->columns == 0)
// 			ft_printf("");
// 		i++;
// 	}
// }
