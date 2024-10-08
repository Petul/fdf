/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:57:24 by pleander          #+#    #+#             */
/*   Updated: 2024/08/29 16:34:15 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft/include/libft.h"

/**
 * @brief Multiplies a 3x3 matrix with a 3x1 column vector
 *
 * @param m Matric
 * @param p Column vector (Point)
 */
static void	mat_mul(float m[3][3], t_point3d *p)
{
	t_point3d	res;

	res.x = round(p->x * m[0][0] + p->y * m[0][1] + p->z * m[0][2]);
	res.y = round(p->x * m[1][0] + p->y * m[1][1] + p->z * m[1][2]);
	res.z = round(p->x * m[2][0] + p->y * m[2][1] + p->z * m[2][2]);
	p->x = res.x;
	p->y = res.y;
	p->z = res.z;
}

/**
 * @brief Rotates the 3D point about the x-axis
 *
 * @param deg Degrees to roatate
 * @param p Point
 */
void	rotate_x(float deg, t_point3d *p)
{
	float	matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], sizeof(float) * 3);
	ft_bzero(matrix[1], sizeof(float) * 3);
	ft_bzero(matrix[2], sizeof(float) * 3);
	matrix[0][0] = 1;
	matrix[1][1] = cos(rad);
	matrix[1][2] = sin(rad);
	matrix[2][1] = -sin(rad);
	matrix[2][2] = cos(rad);
	mat_mul(matrix, p);
}

/**
 * @brief Rotates the 3D point about the y-axis
 *
 * @param deg Degrees to roatate
 * @param p Point
 */
void	rotate_y(float deg, t_point3d *p)
{
	float	matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], sizeof(float) * 3);
	ft_bzero(matrix[1], sizeof(float) * 3);
	ft_bzero(matrix[2], sizeof(float) * 3);
	matrix[0][0] = cos(rad);
	matrix[0][2] = -sin(rad);
	matrix[1][1] = 1;
	matrix[2][0] = sin(rad);
	matrix[2][2] = cos(rad);
	mat_mul(matrix, p);
}

/**
 * @brief Rotates the 3D point about the z-axis
 *
 * @param deg Degrees to roatate
 * @param p Point
 */
void	rotate_z(float deg, t_point3d *p)
{
	float	matrix[3][3];
	float	rad;

	rad = 0.01745 * deg;
	ft_bzero(matrix[0], sizeof(float) * 3);
	ft_bzero(matrix[1], sizeof(float) * 3);
	ft_bzero(matrix[2], sizeof(float) * 3);
	matrix[0][0] = cos(rad);
	matrix[0][1] = -sin(rad);
	matrix[1][0] = sin(rad);
	matrix[1][1] = cos(rad);
	matrix[2][2] = 1;
	mat_mul(matrix, p);
}
