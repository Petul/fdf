/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:07:09 by pleander          #+#    #+#             */
/*   Updated: 2024/08/16 16:09:22 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx42/include/MLX42/MLX42.h"
#include "fdf.h"

void	handle_keypress(mlx_key_data_t keydata, void *context)
{
	t_context	*c;
	
	c = (t_context *)context;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
	{
		
	}
}
