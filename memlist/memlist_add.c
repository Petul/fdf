/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memlist_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:03 by pleander          #+#    #+#             */
/*   Updated: 2024/07/14 10:50:06 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/memlist.h"

/**
 * @brief Adds a manually allocated memory segment to the memlist
 *
 * @param mem Pointer to manually allocated memory segment
 */
void	memlist_add(void *mem)
{
	t_list	**memlist;
	t_list	*n;

	memlist = get_memlist();
	if (!memlist)
		return ;
	n = ft_lstnew(mem);
	if (!n)
		return ;
	ft_lstadd_front(memlist, n);
}
