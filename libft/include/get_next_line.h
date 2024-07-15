/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:28:38 by pleander          #+#    #+#             */
/*   Updated: 2024/05/31 15:21:15 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define OPEN_MAX 10240

char	*get_next_line(int fd);

#endif
