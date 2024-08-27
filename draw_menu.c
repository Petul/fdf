/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:08:40 by pleander          #+#    #+#             */
/*   Updated: 2024/08/23 13:24:53 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

void	draw_menu(t_menu *menu)
{
	ft_memset(menu->img->pixels, 0x0000088, menu->img->width * menu->img->height * sizeof(int32_t));
}
