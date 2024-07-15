/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:10 by pleander          #+#    #+#             */
/*   Updated: 2024/07/14 10:50:11 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"
#include "../include/memlist.h"

/**
 * @brief Allocates bytes memory and adds it to the beginning of the memlist
 *
 * @param bytes number of bytes to allocate
 */
void	*reserve(size_t bytes)
{
	t_list	**memlist;
	t_list	*n;
	void	*mem;

	memlist = get_memlist();
	if (!memlist)
		return (NULL);
	mem = malloc(bytes);
	if (!mem)
		return (NULL);
	n = ft_lstnew(mem);
	if (!n)
		return (NULL);
	ft_lstadd_front(memlist, n);
	return (mem);
}

/**
 * @brief Allocates bytes meory, initializes it to 0 and adds it to the
 * beginning of the memlist
 *
 * @param n number of elements to allocate
 * @param size size of each element
 */
void	*creserve(size_t n, size_t size)
{
	t_list	**memlist;
	t_list	*newlist;
	void	*mem;

	memlist = get_memlist();
	if (!memlist)
		return (NULL);
	mem = ft_calloc(n, size);
	if (!mem)
		return (NULL);
	newlist = ft_lstnew(mem);
	if (!n)
		return (NULL);
	ft_lstadd_front(memlist, newlist);
	return (mem);
}
