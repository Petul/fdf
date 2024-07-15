/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:52:01 by pleander          #+#    #+#             */
/*   Updated: 2024/07/15 16:16:51 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h> 
#include "libft/include/libft.h"
#include "libft/include/get_next_line.h"
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
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (buf[i])
	{
		if (ft_isspace(buf[i]) && !ft_isspace(buf[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static t_list	**read_rows(int fd)
{
	char	*buf;
	t_list	**rows;
	t_list	*new;

	rows = creserve(1, sizeof(t_list *));
	buf = get_next_line(fd);
	if (!buf)
		error_exit(ERR_STR);
	memlist_add(buf);
	while (buf)
	{
		new = ft_lstnew(buf);
		memlist_add(new);
		if (!new)
			error_exit(ERR_STR);
		ft_lstadd_back(rows, new);
		buf = get_next_line(fd);
		memlist_add(buf);
	}
	return (rows);
}

t_map *read_map(char *path)
{
	t_map	*map;
	t_list	**rows;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(strerror(errno));
	rows = read_rows(fd);
	
	return (map);
}
