/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:52:01 by pleander          #+#    #+#             */
/*   Updated: 2024/08/27 15:50:58 by pleander         ###   ########.fr       */
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
		if (ft_isspace(prev) && !ft_isspace(buf[i]))
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
	return (model);
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
