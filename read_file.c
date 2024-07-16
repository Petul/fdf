/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:29:55 by pleander          #+#    #+#             */
/*   Updated: 2024/07/16 13:31:35 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "libft/include/memlist.h"
#include "libft/include/get_next_line.h"
#include "fdf.h"
/**
 * @brief Reads each row into a linked list
 *
 * @param fd file descriptor to read from
 * @return List with data from file
 */
t_list	**read_rows(int fd)
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
