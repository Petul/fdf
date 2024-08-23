/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:05:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/23 10:57:43 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"
#include "libft/include/memlist.h"
#include "fdf.h"


char	*get_menu_text(t_context *c)
{
	char	*t;
	char	*fstr;
	int		chars;
	
	fstr = "%s\n%s\n%s\n%s";
	chars = ft_snprintf(NULL, 0, fstr, ROTATE, TRANSLATE, ROTATE_COLOR, ADJ_HEIGHT); 
	t = creserve(chars + 1, sizeof(char));
	chars = ft_snprintf(t, chars + 1, fstr, ROTATE, TRANSLATE, ROTATE_COLOR, ADJ_HEIGHT); 

	return(t);
}

t_menu	*init_menu(mlx_t *mlx)
{
	t_menu	*m;
	mlx_image_t *menu_img;

	m = creserve(1, sizeof(t_menu));
	if (!m)
		error_exit(ERR_STR);
	m->show = 1;
	menu_img = mlx_new_image(mlx, MENU_WIDTH, MENU_HEIGHT);
	if (!menu_img || (mlx_image_to_window(mlx, menu_img, MENU_X, MENU_Y) < 0))
		error_exit((char *)mlx_strerror(mlx_errno));
	m->img = menu_img;
	m->text_imgs = NULL;
	return (m);
}
