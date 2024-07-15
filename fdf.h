/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:45:55 by pleander          #+#    #+#             */
/*   Updated: 2024/07/15 16:18:28 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERR_STR "Error"

#include <stddef.h>

typedef struct s_map
{
	size_t	columns;
	size_t	rows;
	int		*vertices;
}	t_map;

t_map 	*read_map(char *path);
void	error_exit(char *err_msg);

#endif
