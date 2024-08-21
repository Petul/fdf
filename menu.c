/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:05:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 11:06:13 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/memlist.h"
#include "fdf.h"

t_menu	*init_menu(mlx_t *mlx)
{
	t_menu	*m;
	mlx_image_t *menu_img;

	m = creserve(1, sizeof(t_menu));
	if (!m)
		error_exit(ERR_STR);
	m->show = 1;
	menu_img = mlx_new_image(mlx, 100, 300);
	if (!menu_img || (mlx_image_to_window(mlx, menu_img, 10, 10) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));
	m->img = menu_img;
	return (m);
}
