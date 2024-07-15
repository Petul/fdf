/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:49:51 by pleander          #+#    #+#             */
/*   Updated: 2024/07/15 12:44:09 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/memlist.h"

/**
 * @brief Returns the memlist or initializes it if it does not exist.
 *
 * @return Address of the memlist
 */
t_list	**get_memlist(void)
{
	static t_list	**memlist;

	if (memlist == NULL)
	{
		memlist = malloc(sizeof(t_list *));
		if (!memlist)
			return (NULL);
		*memlist = NULL;
	}
	return (memlist);
}

/**
 * @brief Releases all memory tracked by the memlist and all memory used by
 * the memlist itself.
 */
void	memlist_release_all(void)
{
	t_list	**memlist;

	memlist = get_memlist();
	if (!memlist)
		return ;
	ft_lstclear(memlist, &free);
	free(memlist);
}
