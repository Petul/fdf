/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:36:42 by pleander          #+#    #+#             */
/*   Updated: 2024/05/31 09:55:49 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_vsnprintf(char *output, size_t size, const char *fstr, va_list args)
{
	size_t		loc;
	t_bool		t;
	t_result	res;
	va_list		args2;

	va_copy(args2, args);
	init_t_result(output, size, &res);
	loc = 0;
	while (loc < ft_strlen(fstr))
	{
		if (fstr[loc] == '%')
		{
			t = process_fspec((char *)fstr + loc, &args2, &loc, &res);
			if (t == FALSE)
				return (-1);
			continue ;
		}
		write_char(fstr[loc++], &res);
	}
	if (res.written >= res.buf_size && size > 0)
		res.buffer[res.buf_size - 1] = '\0';
	else
		write_char('\0', &res);
	return (res.written - 1);
}

int	ft_snprintf(char *output, size_t size, const char *fstr, ...)
{
	int		written;
	va_list	args;

	va_start(args, fstr);
	written = ft_vsnprintf(output, size, fstr, args);
	va_end(args);
	return (written);
}

int	ft_dprintf(int fd, const char *fstr, ...)
{
	int		written;
	char	*output;
	va_list	args;

	va_start(args, fstr);
	written = ft_vsnprintf((char *) NULL, 0, fstr, args);
	if (written < 0)
		return (written);
	output = ft_calloc(written + 1, sizeof(char));
	written = ft_vsnprintf(output, written + 1, fstr, args);
	print_string(fd, output, written);
	free(output);
	va_end(args);
	return (written);
}

int	ft_printf(const char *fstr, ...)
{
	int		written;
	char	*output;
	va_list	args;

	va_start(args, fstr);
	written = ft_vsnprintf((char *) NULL, 0, fstr, args);
	if (written < 0)
		return (written);
	output = ft_calloc(written + 1, sizeof(char));
	written = ft_vsnprintf(output, written + 1, fstr, args);
	print_string(1, output, written);
	free(output);
	va_end(args);
	return (written);
}
