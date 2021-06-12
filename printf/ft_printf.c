/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:31:51 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:15:56 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_options(t_op *op)
{
	op->minus = 0;
	op->zero = 0;
	op->width = 0;
	op->precision = 0;
	op->is_precision = 0;
	op->nbr_minus = 0;
	op->type = 0;
}

int		handle_type(t_op op, va_list ap)
{
	int cnt;

	cnt = 0;
	if (op.type == 'c')
		cnt += print_c(op, va_arg(ap, int));
	else if (op.type == 's')
		cnt = print_s(op, va_arg(ap, char *));
	else if (op.type == 'd' || op.type == 'i')
		cnt = print_nbr(&op, va_arg(ap, int));
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

void	parse_precision(const char **format, t_op *op, va_list ap)
{
	op->is_precision = 1;
	(*format)++;
	if (**format == '*')
	{
		op->precision = va_arg(ap, int);
		if (op->precision < 0)
		{
			op->precision = 0;
			op->is_precision = 0;
		}
		(*format)++;
	}
	while (**format == '-')
	{
		(*format)++;
		op->width = 0;
		op->minus = 1;
		while ('0' <= **format && **format <= '9')
			op->width = op->width * 10 + (*((*format)++) - '0');
		op->is_precision = 0;
		op->precision = 0;
	}
	while ('0' <= **format && **format <= '9')
		op->precision = op->precision * 10 + (*((*format)++) - '0');
}

void	parse_options(const char **format, t_op *op, va_list ap)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			op->minus = 1;
		else
			op->zero = 1;
		(*format)++;
	}
	if (**format == '*')
	{
		op->width = va_arg(ap, int);
		if (op->width < 0)
		{
			op->minus = 1;
			op->width *= -1;
		}
		(*format)++;
	}
	while ('0' <= **format && **format <= '9')
		op->width = op->width * 10 + (*((*format)++) - '0');
	while (**format == '-' || **format == '0')
		(*format)++;
	if (**format == '.')
		parse_precision(format, op, ap);
	op->type = **format;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_op	op;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*(format))
	{
		if (*(format) != '%')
			cnt += ft_putchar(*format);
		else
		{
			format++;
			init_options(&op);
			parse_options(&format, &op, ap);
			if (op.minus == 1 && op.zero == 1)
				op.zero = 0;
			if (op.is_precision == 1 && (op.type != 's' && op.type != '%'))
				op.zero = 0;
			cnt += handle_type(op, ap);
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
