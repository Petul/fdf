/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:08:40 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 10:50:41 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/memlist.h"
#include "fdf.h"

t_menu	*init_menu(void)
{
	t_menu	*m;

	m = creserve(1, sizeof(t_menu));
	if (!m)
		error_exit(ERR_STR);
	m->show = 1;
	return (m);
}
void	draw_menu(t_menu *menu)
{
	ft_memset(menu->img->pixels, 0xFFFFFFDD, menu->img->width * menu->img->height * sizeof(int32_t));
}
