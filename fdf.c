/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:49 by pleander          #+#    #+#             */
/*   Updated: 2024/08/23 13:02:47 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "libft/include/memlist.h"
#include "fdf.h"
#include <stdlib.h>

static void	register_hooks(t_context *c)
{
	mlx_resize_hook(c->mlx, &handle_resize, c);
	mlx_scroll_hook(c->mlx, &handle_zoom, c);
	mlx_key_hook(c->mlx, &handle_keypress, c);
}

int	fdf(char *path)
{
	t_context	*c;
	mlx_t		*mlx;
	t_model		*model;
	char		*text;

	model = read_model(path);
	c = creserve(1, sizeof(t_context));
	if (!c)
		error_exit(ERR_STR);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		error_exit((char *)mlx_strerror(mlx_errno));
	c->mlx = mlx;
	c->map = init_map(mlx, model);
	c->menu = init_menu(mlx);
	reset_map(c);
	draw_map(c->map, c->map->img);
	draw_menu(c->menu);
	text = get_menu_text(c);
	write_menu_text(mlx, c->menu, text);
	release(text);
	register_hooks(c);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
