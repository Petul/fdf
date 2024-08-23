/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:47:09 by pleander          #+#    #+#             */
/*   Updated: 2024/08/23 10:59:31 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/include/libft.h"
#include "mlx42/include/MLX42/MLX42.h"
#include "libft/include/memlist.h"
#include "fdf.h"

static int	count_rows(char	*text)
{
	int	rows;
	
	if (!text)
		return (0);
	rows = 1;
	while(*text)
	{
		if (*text == '\n' && *(text + 1) != 0)
			rows++;
		text++;
	}
	return(rows);
}

static void	write_text(mlx_t *mlx, mlx_image_t **text_imgs, char *text)
{
	int		y;
	int		i;
	char	*line;
	char	*nl;

	y = MENU_Y;
	i = 0;
	nl = ft_strchr(text, '\n');
	while (nl)
	{
		line = ft_substr(text, 0, nl - text);
		if (!line)
			error_exit(ERR_STR);
		text_imgs[i] = mlx_put_string(mlx, line, MENU_X + 10, y);
		free(line);
		text = nl + 1;
		nl = ft_strchr(text, '\n');
		i++;
		y += FONT_HEIGHT - 2;
	}
	if (text != NULL)
		text_imgs[i] = mlx_put_string(mlx, text, MENU_X + 10, y);
}

static void	clear_text(mlx_t *mlx, mlx_image_t **text_imgs)
{
	while (*text_imgs)
	{
		mlx_delete_image(mlx, *text_imgs);
		release(*text_imgs);
		text_imgs++;
	}
	release(text_imgs);
	text_imgs = NULL;
}

mlx_image_t	**write_menu_text(mlx_t *mlx, t_menu *m, char *text)
{
	int rows;

	rows = count_rows(text);
	if (m->text_imgs != NULL)
		clear_text(mlx, m->text_imgs);
	m->text_imgs = creserve(rows + 1, sizeof(mlx_image_t *));
	if (!m->text_imgs)
		error_exit(ERR_STR);
	write_text(mlx, m->text_imgs, text);
	return (m->text_imgs);
}
