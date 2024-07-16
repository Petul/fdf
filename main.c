/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:38:13 by pleander          #+#    #+#             */
/*   Updated: 2024/07/16 15:29:35 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/include/memlist.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	map = read_map(argv[1]);
	fdf(map);
	release(map);
	memlist_release_all();

}
