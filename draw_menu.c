/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:08:40 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 11:06:26 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_menu *menu)
{
	ft_memset(menu->img->pixels, 0xFFFFFFDD, menu->img->width * menu->img->height * sizeof(int32_t));
}
