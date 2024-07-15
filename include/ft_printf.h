/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:08:41 by pleander          #+#    #+#             */
/*   Updated: 2024/05/31 09:56:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

# define STDOUT 1
# define BASE_DEC "0123456789"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define BASE_HEX_LOWER "0123456789abcdef"
# define NULL_STR "(null)"

typedef unsigned char	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct s_fspec
{
	char	format;
	size_t	len;
	t_bool	alternate_form;
	t_bool	zero_padding;
	t_bool	negative_field_width;
	t_bool	space_before_pos;
	t_bool	plus_before_pos;
	t_bool	has_dot;
	size_t	min_field_width;
	size_t	precision;
}	t_fspec;

typedef struct s_result
{
	char	*buffer;
	size_t	buf_size;
	size_t	written;
}			t_result;

int		ft_printf(const char *fstring, ...);
int		ft_snprintf(char *output, size_t size, const char *fstr, ...);
int		ft_dprintf(int fd, const char *fstr, ...);
int		ft_vsnprintf(char *output, size_t size, const char *fstr, va_list args);
void	write_char(int data, t_result *r);
void	write_string(char *data, size_t n, t_result *r);
t_bool	print_char(int fd, int data);
t_bool	print_string(int fd, char *data, size_t n);
t_fspec	*parse_conversion(char *conversion);
t_bool	convert_char(t_fspec *s, int data, t_result *r);
t_bool	convert_string(t_fspec *s, char *data, t_result *r);
t_bool	convert_pointer(t_fspec *s, char *data, t_result *r);
t_bool	convert_decimal(t_fspec *s, int data, t_result *r);
t_bool	convert_unsigned(t_fspec *s, unsigned int data, t_result *r);
t_bool	convert_hex_upper(t_fspec *s, int data, t_result *r);
t_bool	convert_hex_lower(t_fspec *s, int data, t_result *r);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
char	*apply_plus(t_fspec *s, char *num);
char	*apply_alternate_hex_form(t_fspec *s, char *num, char *pre_str);
char	*apply_field_width(t_fspec *s, char *data);
char	*apply_precision(t_fspec *s, char *num);
char	*apply_space_before_pos(t_fspec *s, char *num);
char	*apply_string_precision(t_fspec *s, char *str);
int		only_zero_or_space(char *num);
void	float_sign(char *num);
void	float_space(char *num);
void	init_t_result(char *output, size_t buf_size, t_result *res);
t_bool	process_fspec(char *f, va_list *args, size_t *loc, t_result *r);

#endif
