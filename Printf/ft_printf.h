/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:17:58 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/23 01:02:01 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef	struct	s_options
{
    int		minus;
    int		zero;
    int		width;
    int		precision;
	int		is_precision;
    char	type;
}				t_options;

void    init_options(t_options *op);
void    flag_options(const char **format, t_options *op);
void    update_options(const char **format, va_list ap, t_options *op);
int     handle_type(t_options op, va_list ap);
int     ft_printf(const char *format, ...);

int     print_c(t_options op, int c);
int     print_s(t_options op, char *str);
int     print_nbr(t_options op, int n);
int     print_u_nbr(t_options op, unsigned int n);
int     print_hex(t_options op, unsigned int n);
int     print_addr(t_options op, void *ptr);

char	*treat_to_hex(t_options op, unsigned int n, char *ans);
int     treat_precision_s(t_options op, char *str, char **tmp_s);
int     treat_precision_n(t_options op, char **tmp_n, char *n, int sign);

int     treat_width_c(t_options op);
int     treat_width_s(t_options op, char **tmp_s);
int     treat_width_n(t_options op, char **tmp_n);

#endif
