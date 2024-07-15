/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:58 by pleander          #+#    #+#             */
/*   Updated: 2024/07/15 12:44:26 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMLIST_H
# define MEMLIST_H

# include "libft.h"

t_list	**get_memlist(void);
void	memlist_release_all(void);
void	*reserve(size_t bytes);
void	*creserve(size_t n, size_t size);
void	release(void *mem);

#endif
