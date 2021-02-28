/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:17:58 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 15:50:23 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_op
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		is_precision;
	int		nbr_minus;
	char	type;
}					t_op;
int					ft_putchar(int c);
int					ft_putstr(char *str);
unsigned long		get_hex_size(unsigned long n);
void				reverse_str(char **str);
int					order_print_out(t_op op, char *tmp_s, int idx);
void				treat_to_hex(t_op op, unsigned long long n, \
		char **tmp_hex, int idx);
int					treat_width_c(t_op op);
int					treat_width_s(t_op op, char *tmp_s);
int					treat_width_n(t_op op, char *tmp_n);
char				*treat_precision_s(t_op op, char *tmp_s);
char				*treat_precision_n(t_op op, char *n);
int					print_nbr(t_op *op, int n);
int					print_u_nbr(t_op op, unsigned int n);
int					print_s(t_op op, char *s);
int					print_c(t_op op, int c);
int					print_hex(t_op op, unsigned int n);
int					print_addr(t_op op, void *addr);
void				init_options(t_op *op);
int					handle_type(t_op op, va_list ap);
int					ft_printf(const char *format, ...);
void				parse_options(const char **format, t_op *op, va_list ap);
void				parse_precision(const char **format, t_op *op, va_list ap);
int					print_not_minus(t_op op, char *tmp_s, int idx);

#endif
