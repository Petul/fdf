/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:45:55 by pleander          #+#    #+#             */
/*   Updated: 2024/07/19 20:56:21 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/include/libft.h"

# define DEFAULT_COLOR 0x00
# define ERR_STR "Error"
# define WIDTH 512
# define HEIGHT 512
# define PADDING 10

typedef struct	s_point2d
{
	int	x;
	int	y;
	uint32_t color;
}	t_point2d;

typedef struct	s_point3d
{
	int	x;
	int	y;
	int	z;
	uint32_t color;
}	t_point3d;

typedef struct	s_ver
{
	int height;
	int	color;
}	t_ver;

typedef struct	s_map
{
	size_t		rows;
	size_t		columns;
	size_t		xy_scale;
	size_t		z_scale;
	int			x_translate;
	int			y_translate;
	t_ver		*vertices;
	t_point2d	**sc;
}	t_map;

int			fdf(t_map *map);
t_map		*read_map(char *path);
void		error_exit(char *err_msg);
void		iter_2darr(char **arr, void (fn)(void *));
t_list		**read_rows(int fd);
void		draw_line(t_point2d start, t_point2d end, mlx_image_t *img);
t_point3d	get_3d_point(size_t col, size_t row, t_map *map);
void		calculate_projection(t_map *map);
void		draw_map(t_map *map, mlx_image_t *img);
void		rotate_x(int deg, t_point3d *p);
void		rotate_y(int deg, t_point3d *p);
void		rotate_z(int deg, t_point3d *p);
void		calculate_auto_scale(t_map *map);

#endif
