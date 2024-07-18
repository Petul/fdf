/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:52:36 by pleander          #+#    #+#             */
/*   Updated: 2024/07/18 19:29:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft/include/libft.h"


static void mat_mul(float m[3][3], t_point3d *p)
{
	t_point3d res;

	res.x = p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2];
	res.y = p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2];
	res.z = p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2];
	p->x = res.x;
	p->y = res.y;
	p->z = res.z;
}

void	rotate_x(int deg, t_point3d *p)
{
	float	matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], 3);
	ft_bzero(matrix[1], 3);
	ft_bzero(matrix[2], 3);
	matrix[0][0] = 1;
	matrix[1][1] = cos(rad);
	matrix[1][2] = -sin(rad);
	matrix[2][1] = sin(rad);
	matrix[2][2] = cos(rad); //copy previous value?
	mat_mul(matrix, p);
}

void	rotate_y(int deg, t_point3d *p)
{
	float		matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], 3);
	ft_bzero(matrix[1], 3);
	ft_bzero(matrix[2], 3);
	matrix[0][0] = cos(rad);
	matrix[0][2] = sin(rad);
	matrix[1][1] = 1;
	matrix[2][0] = -sin(rad);
	matrix[2][2] = cos(rad);
	mat_mul(matrix, p);
}

void	rotate_z(int deg, t_point3d *p)
{
	float		matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], 3);
	ft_bzero(matrix[1], 3);
	ft_bzero(matrix[2], 3);
	matrix[0][0] = cos(rad);
	matrix[0][1] = -sin(rad);
	matrix[1][0] = sin(rad);
	matrix[1][1] = cos(rad);
	matrix[2][2] = 1;
	mat_mul(matrix, p);
}
