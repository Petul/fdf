/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:05:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:55:23 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"
#include "libft/include/memlist.h"
#include "fdf.h"

/**
 * @brief Constructs the menu text and return a string containing the text
 *
 * @param c context
 * @return string containing the text
 */
char	*get_menu_text(t_context *c)
{
	char	*t;
	char	*fstr;
	int		chars;

	if (!c)
		error_exit(ERR_STR);
	fstr = "%s\n%s\n%s\n%s\n%s\n%s\n%s";
	chars = ft_snprintf(NULL, 0, fstr, M_HEAD, M_EXIT, M_RESET, M_ROT,
			M_TRANS, M_COLOR, M_HEIGHT);
	if (chars < 0)
		error_exit(ERR_STR);
	t = creserve(chars + 1, sizeof(char));
	chars = ft_snprintf(t, chars + 1, fstr, M_HEAD, M_EXIT, M_RESET, M_ROT,
			M_TRANS, M_COLOR, M_HEIGHT);
	if (chars < 0)
		error_exit(ERR_STR);
	return (t);
}

/**
 * @brief Initializes the menu structure
 *
 * @param mlx
 * @return menu struct
 */
t_menu	*init_menu(mlx_t *mlx)
{
	mlx_image_t	*menu_img;
	t_menu		*m;

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
