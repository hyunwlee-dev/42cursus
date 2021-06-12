/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:19:54 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:16:12 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_op op, int c)
{
	int	cnt;

	cnt = 0;
	if (op.minus == 1)
	{
		cnt += ft_putchar(c);
		cnt += treat_width_c(op);
	}
	else
	{
		cnt += treat_width_c(op);
		cnt += ft_putchar(c);
	}
	return (cnt);
}
