/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:38:13 by pleander          #+#    #+#             */
/*   Updated: 2024/08/21 12:38:10 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/include/memlist.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	fdf(argv[1]);
	memlist_release_all();
}
