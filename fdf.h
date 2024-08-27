/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:45:55 by pleander          #+#    #+#             */
/*   Updated: 2024/08/24 09:35:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/include/libft.h"

# define WIDTH 1024
# define HEIGHT 1024
# define PADDING 10
# define DEFAULT_COLOR 0xFFFFFFFF
# define HEX_BASE "0123456789ABCDEF"
# define ERR_STR "Error"
# define DEFFAULT_X_ROT 35
# define DEFFAULT_Y_ROT 0
# define DEFFAULT_Z_ROT -45
# define N_COLORS 32
# define MENU_WIDTH 200
# define MENU_HEIGHT 250
# define MENU_X 10
# define MENU_Y 10

# define FONT_HEIGHT 20
# define M_HEAD "FDF"
# define M_ROT "Rotate model:\nh, j, k, l"
# define M_TRANS "Translate model:\nw, a, s, d"
# define M_COLOR "Rotate color:\nc"
# define M_HEIGHT "Adjust height:\nz/x"
# define M_EXIT "Exit: ESC"
# define M_RESET "Reset: r"


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
	t_color	*colors;
}	t_ver;

typedef struct	s_settings
{
	float	xy_scale;
	float	z_scale;
	int		x_trans;
	int		y_trans;
	int		x_offset;
	int		y_offset;
	int		x_rot;
	int		y_rot;
	int		z_rot;
	size_t	current_color;
	size_t	thickness;
}	t_settings;

typedef struct	s_model
{
	size_t		rows;
	size_t		columns;
	int			max_z;
	int			min_z;
	t_ver		*vertices;
}	t_model;

typedef struct	s_map
{
	mlx_image_t	*img;
	t_model		*model;
	t_settings	*settings;
	t_point2d	**sc;
}	t_map;

typedef struct	s_menu
{
	mlx_image_t	*img;
	mlx_image_t	**text_imgs;
	size_t		x_pos;
	size_t		y_pos;
	int			show;
}	t_menu;

typedef struct s_context
{
	mlx_t		*mlx;
	t_map		*map;
	t_menu		*menu;
	
}	t_context;

int			fdf(char *path);
t_model		*read_model(char *path);
void		error_exit(char *err_msg);
void		iter_2darr(char **arr, void (fn)(void *));
t_list		**read_rows(int fd);
void		draw_line(t_point2d start, t_point2d end, size_t thickness, mlx_image_t *img);
t_point3d	get_3d_point(size_t col, size_t row, t_map *map);
void		calculate_projection(t_map *map);
void		draw_map(t_map *map, mlx_image_t *img);
void		rotate_x(int deg, t_point3d *p);
void		rotate_y(int deg, t_point3d *p);
void		rotate_z(int deg, t_point3d *p);
void		calculate_auto_scale(t_map *m);
void		upper(char *str);
uint32_t	get_rgba(t_color c);
t_color		get_color(uint32_t rgba);
t_color		interpolate_colors(t_color start, t_color end, float d);
void		calculate_translation(t_map *map);
void		handle_keypress(mlx_key_data_t keydata, void *context);
void		reset_map(void	*context);
void		paint_vertices(t_model *m);
void		draw_menu(t_menu *menu);
t_menu		*init_menu(mlx_t *mlx);
void		zoom_image(t_map *m, double ydelta);
void		resize_image(t_map *m);
void		handle_resize(int32_t width, int32_t height, void *context);
void		handle_zoom(double xdelta, double ydelta, void *context);
t_map		*init_map(mlx_t *mlx, t_model *model);
mlx_image_t	**write_menu_text(mlx_t *mlx, t_menu *m, char *text);
char		*get_menu_text(t_context *c);
void		update_max_min(t_model * m, size_t v_i);

#endif
