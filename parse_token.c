/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:47:47 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:50:30 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/memlist.h"
#include "fdf.h"

/**
 * @brief Parses color information from a field
 *
 * @param ver vertices
 * @param tok currect field
 * @param delim location of the delimeter
 */
static void	parse_color_info(t_ver *ver, char *tok, char *delim)
{
	char	*height;
	char	*color;

	height = ft_substr(tok, 0, delim - tok);
	if (!height)
		error_exit(ERR_STR);
	memlist_add(height);
	color = ft_substr(tok, delim - tok + 1, ft_strlen(tok) - (delim - tok));
	if (!color)
		error_exit(ERR_STR);
	memlist_add(color);
	upper(color);
	ver->height = ft_atoi(height);
	ver->colors[0]
		= get_color((ft_atoi_base(color + 2, HEX_BASE) << 8) | (0x000000FF));
	release(height);
	release(color);
}

/**
 * @brief Parses height and color information from the token
 *
 * @param ver Vertice the place the information in
 * @param tok Token to parse
 */
void	parse_token(t_ver *ver, char *tok)
{
	char	*delim;

	ver->colors = creserve(N_COLORS, sizeof(t_color));
	if (!ver->colors)
		error_exit(ERR_STR);
	delim = ft_strchr(tok, ',');
	if (delim)
		parse_color_info(ver, tok, delim);
	else
	{
		ver->height = ft_atoi(tok);
		ver->colors[0] = get_color(DEFAULT_COLOR);
	}
}
