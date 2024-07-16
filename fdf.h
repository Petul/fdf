/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:45:55 by pleander          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:12 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEFAULT_COLOR 0x00
# define ERR_STR "Error"

#include "libft/include/libft.h"

typedef struct	s_ver
{
	int height;
	int	color;
}	t_ver;

typedef struct	s_map
{
	size_t	rows;
	size_t	columns;
	t_ver	*vertices;
}	t_map;

int		fdf(t_map *map);
t_map 	*read_map(char *path);
void	error_exit(char *err_msg);
void	iter_2darr(char **arr, void (fn)(void *));
t_list	**read_rows(int fd);

#endif
