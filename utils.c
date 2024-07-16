/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:21:30 by pleander          #+#    #+#             */
/*   Updated: 2024/07/16 13:51:17 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"
#include "fdf.h"

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
