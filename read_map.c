/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:52:01 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 12:30:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h> 
#include "libft/include/libft.h"
#include "libft/include/memlist.h"
#include "fdf.h"

/**
 * @brief Calculates amount of columns in a buffer
 *
 * @param buf text buffer
 * @return amount of columns in a buffer
 */
static size_t	calculate_columns(char *buf)
{
	size_t	count;
	size_t	i;
	char	prev;

	count = 0;
	i = 0;
	prev = ' ';
	while (buf[i] && buf[i] != '\n')
	{
		if (ft_isspace(prev) && !ft_isspace(buf[i])) // ie a new word is starting
			count++;
		prev = buf[i];
		i++;
	}
	return (count);
}

/**
 * @brief Initializes the map and calculates number of rows and columns
 *
 * @param rows list of row buffers
 * @return the initialized map
 */
static t_model	*init_model(t_list **rows)
{
	t_model	*model;
	t_list	*cur;

	model = reserve(sizeof(t_model));
	if (!model)
		error_exit(ERR_STR);
	model->rows = ft_lstsize(*rows);
	model->columns = calculate_columns((*rows)->content);
	cur = (*rows)->next;
	while (cur)
	{
		if (model->columns != calculate_columns(cur->content))
			error_exit("Map error");
		cur = cur->next;
	}
	model->vertices = reserve(model->columns * model->rows * sizeof(t_ver));
	if (!model->vertices)
		error_exit(ERR_STR);
	//map->sc = creserve(map->rows, sizeof(t_point2d *));
	// map->settings = creserve(1, sizeof(t_settings));
	// if (!map->vertices || !map->sc || !map->settings)
	// 	error_exit(ERR_STR);
	//i = 0;
	// while (i < map->rows)
	// {
	// 	map->sc[i] = creserve(map->columns, sizeof(t_point2d));
	// 	if (!map->sc[i])
	// 		error_exit(ERR_STR);
	// 	i++;
	// }
	return (model);
}

/**
 * @brief Parses height and color information from the token
 *
 * @param ver Vertice the place the information in
 * @param tok Token to parse
 */
static void	parse_token(t_ver *ver, char *tok)
{
	char	*delim;
	char	*height;
	char	*color;

	ver->colors = creserve(N_COLORS, sizeof(t_color));
	if (!ver->colors)
		error_exit(ERR_STR);
	delim = ft_strchr(tok, ',');
	if (delim)
	{
		height = ft_substr(tok, 0, delim - tok);
		memlist_add(height);
		color = ft_substr(tok, delim - tok + 1, ft_strlen(tok) - (delim - tok));
		upper(color);
		memlist_add(color);
		if (!height || !color)
			error_exit(ERR_STR);
		ver->height = ft_atoi(height); // Check overflow?
		ver->colors[0] = get_color((ft_atoi_base(color + 2, HEX_BASE) << 8) | (0x000000FF));
		release(height);
		release(color);
	}
	else
	{
		ver->height = ft_atoi(tok);
		ver->colors[0] = get_color(DEFAULT_COLOR);
	}
}

static void update_max_min(t_model * m, size_t v_i)
{
	if (v_i == 0 || m->vertices[v_i].height > m->max_z)
		m->max_z = m->vertices[v_i].height;
	if (v_i == 0 || m->vertices[v_i].height < m->min_z)
		m->min_z = m->vertices[v_i].height;
}

/**
 * @brief Reads a list of rows and parses their information into the map
 *
 * @param map Map where the parsed information is stored
 * @param rows List of rows in the file
 */
static void	parse_rows_to_map(t_model *m, t_list **rows)
{
	t_list	*cur;
	char	**toks;
	size_t	t_i;
	size_t	v_i;

	v_i = 0;
	cur = *rows;
	while (cur)
	{
		t_i = 0;
		toks = ft_split(cur->content, ' ');
		iter_2darr(toks, &memlist_add);
		while (toks[t_i] && toks[t_i][0] != '\n')
		{
			parse_token(m->vertices + v_i, toks[t_i]);
			update_max_min(m, v_i);
			v_i++;
			t_i++;
		}
		cur = cur->next;
		iter_2darr(toks, &release);
	}
}

/**
 * @brief Read the map from file
 *
 * @param path path to the file
 * @return the map
 */
t_model	*read_model(char *path)
{
	t_model	*model;
	t_list	**rows;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno));
	rows = read_rows(fd);
	model = init_model(rows);
	parse_rows_to_map(model, rows);
	paint_vertices(model);
	return (model);
}
