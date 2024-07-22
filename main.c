/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:38:13 by pleander          #+#    #+#             */
/*   Updated: 2024/07/22 16:20:53 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/include/memlist.h"

int	main(int argc, char **argv)
{
	t_context	*context;
	t_map		*map;

	if (argc != 2)
		return (1);
	map = read_map(argv[1]);
	context = creserve(1, sizeof(t_context));
	context->map = map;
	fdf(context);
	release(map);
	memlist_release_all();

}
