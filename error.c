/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:38:03 by pleander          #+#    #+#             */
/*   Updated: 2024/07/15 16:19:18 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/include/ft_printf.h"
#include "libft/include/memlist.h"

/**
 * @brief Prints an error message and releases all memory in the memlist
 *
 * @param err_msg Error message to print
 */
void	error_exit(char *err_msg)
{
	if (err_msg)
		ft_dprintf(STDERR_FILENO, "%s %s%s", "fdf:", err_msg, "\n");
	memlist_release_all();
	exit(1);
}
