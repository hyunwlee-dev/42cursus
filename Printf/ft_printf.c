/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:31:51 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:44:44 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void init_options(t_options *op)
{
    op->minus = 0;
    op->zero = 0;
    op->precision = 0;
    op->is_precision = 0;
    op->width = 0;
    op->width = 0;
}

void flag_options(const char **format, t_options *op)
{
    while (**format == '-')
    {
        op->minus = 1;
        (*format)++;
    }
    while (**format == '0')
    {
        op->zero = 1;
        (*format)++;
    }
}

void update_options(const char **format, va_list ap, t_options *op)
{
    flag_options(format, op);
    if (**format == '*')
    {
        op->width = va_arg(ap, int);
        if (op->width < 0) {
            op->minus = 1;
            op->width *= -1;
        }
        (*format)++;
    }
    while ('0' <= **format && **format <= '9')
        op->width = op->width * 10 + (*((*format)++) - '0');
    if (**format == '.') {
        op->is_precision = 1;
        (*format)++;
        if (**format == '*')
        {
            op->precision = va_arg(ap, int);
            (*format)++;
        }
        while (**format == '0')
            (*format)++;
        while ('0' <= **format && **format <= '9')
            op->precision = op->precision * 10 + (*((*format)++) - '0');
    }
    op->type = **format;
}

int handle_type(t_options op, va_list ap)
{
    int cnt;

    cnt = 0;
    if (op.type == 'c')
        cnt = print_c(op, va_arg(ap, int));
    else if (op.type == 's')
        cnt = print_s(op, va_arg(ap, char *));
    else if (op.type == 'd' || op.type == 'i')
        cnt = print_nbr(op, va_arg(ap, int));
    else if (op.type == 'x' || op.type == 'X')
        cnt = print_hex(op, va_arg(ap, unsigned int));
    else if (op.type == 'u')
        cnt = print_u_nbr(op, va_arg(ap, unsigned int));
    else if (op.type == 'p')
        cnt = print_addr(op, va_arg(ap, void *));
    else if (op.type == '%')
        cnt = print_c(op, '%');
    return (cnt);
}

int ft_printf(const char *format, ...)
{
    va_list     ap;
    t_options   op;
    int         cnt;

    va_start(ap, format);
    cnt = 0;
    while (*(format)) {
        if (*(format) != '%')
            cnt += ft_putchar_fd(*(format), 1);
        else
        {
            format++;
            init_options(&op);
            update_options(&format, ap, &op);
            cnt += handle_type(op,ap);
        }
        format++;
    }
    va_end(ap);
    return (cnt);
}
