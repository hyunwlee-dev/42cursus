/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:21:25 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:23:51 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_width_c(t_op op)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = op.width - 1;
	while (idx-- > 0)
	{
		if (op.zero)
			cnt += ft_putchar('0');
		else
			cnt += ft_putchar(' ');
	}
	return (cnt);
}

int	print_not_minus(t_op op, char *tmp_s, int idx)
{
	int	cnt;

	cnt = 0;
	if (op.zero && op.nbr_minus)
		cnt += ft_putchar('-');
	if (op.zero && op.type == 'p')
		cnt += ft_putstr("0x");
	while (idx > 0)
	{
		if (op.zero == 1)
			cnt += ft_putchar('0');
		else
			cnt += ft_putchar(' ');
		idx--;
	}
	if (!op.zero && op.nbr_minus)
		cnt += ft_putchar('-');
	if (!op.zero && op.type == 'p')
		cnt += ft_putstr("0x");
	cnt += ft_putstr(tmp_s);
	return (cnt);
}

int	order_print_out(t_op op, char *tmp_s, int idx)
{
	int cnt;

	cnt = 0;
	if (op.minus == 1)
	{
		if (op.nbr_minus)
			cnt += ft_putchar('-');
		if (op.type == 'p')
			cnt += ft_putstr("0x");
		cnt += ft_putstr(tmp_s);
		while (idx > 0)
		{
			if (op.zero == 1)
				cnt += ft_putchar('0');
			else
				cnt += ft_putchar(' ');
			idx--;
		}
	}
	else
		cnt += print_not_minus(op, tmp_s, idx);
	return (cnt);
}

int	treat_width_n(t_op op, char *tmp_n)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = (op.nbr_minus) ? 1 : 0;
	if (op.type == 'p')
		len = 2;
	if (op.width <= (int)ft_strlen(tmp_n) + len)
	{
		if (op.nbr_minus)
			cnt += ft_putchar('-');
		if (op.type == 'p')
			cnt += ft_putstr("0x");
		cnt += ft_putstr(tmp_n);
	}
	else
		cnt += order_print_out(op, tmp_n, (op.width - (int)ft_strlen(tmp_n) \
					- len));
	return (cnt);
}

int	treat_width_s(t_op op, char *tmp_s)
{
	int	cnt;

	cnt = 0;
	if (op.width <= (int)ft_strlen(tmp_s))
		cnt += ft_putstr(tmp_s);
	else
		cnt += order_print_out(op, tmp_s, (op.width - (int)ft_strlen(tmp_s)));
	return (cnt);
}
