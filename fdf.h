/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:45:55 by pleander          #+#    #+#             */
/*   Updated: 2024/08/15 14:29:40 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/include/libft.h"

# define WIDTH 512
# define HEIGHT 512
# define PADDING 10
//# define DEFAULT_COLOR 0x00000000
# define DEFAULT_COLOR 0xFFFFFFFF
# define HEX_BASE "0123456789ABCDEF"
# define ERR_STR "Error"

typedef struct	s_color
{
	uint8_t r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_color;

typedef struct	s_point2d
{
	int			x;
	int			y;
	t_color		color;
}	t_point2d;

typedef struct	s_point3d
{
	int			x;
	int			y;
	int			z;
	t_color		color;
}	t_point3d;

typedef struct	s_ver
{
	int		height;
	t_color	color;
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

typedef struct s_context
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	
}	t_context;

int			fdf(t_context *context);
t_map		*read_map(char *path);
void		error_exit(char *err_msg);
void		iter_2darr(char **arr, void (fn)(void *));
t_list		**read_rows(int fd);
void		draw_line(t_point2d start, t_point2d end, mlx_image_t *img);
t_point3d	get_3d_point(size_t col, size_t row, t_map *map);
void	calculate_projection(t_map *map);
void draw_map(mlx_t *mlx, t_map *map, mlx_image_t *img);
void		rotate_x(int deg, t_point3d *p);
void		rotate_y(int deg, t_point3d *p);
void		rotate_z(int deg, t_point3d *p);
void	calculate_auto_scale(t_context *c);
void	upper(char *str);
uint32_t	get_rgba(t_color c);
t_color	get_color(uint32_t rgba);

#endif
