/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:20:14 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:04:52 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(t_op *op, int n)
{
	int		cnt;
	char	*tmp_n;
	long	tmp;

	cnt = 0;
	tmp = (long)n;
	if (tmp < 0)
	{
		op->nbr_minus = 1;
		tmp *= -1;
	}
	if (op->is_precision && (!op->precision) && n == 0)
		tmp_n = ft_strdup("");
	else
		tmp_n = treat_precision_n(*op, ft_itoa(tmp));
	cnt += treat_width_n(*op, tmp_n);
	free(tmp_n);
	tmp_n = 0;
	return (cnt);
}

int	print_u_nbr(t_op op, unsigned int n)
{
	int		cnt;
	char	*tmp_n;

	cnt = 0;
	if (op.is_precision && (!op.precision) && n == 0)
		tmp_n = ft_strdup("");
	else
		tmp_n = treat_precision_n(op, ft_itoa(n));
	cnt += treat_width_n(op, tmp_n);
	free(tmp_n);
	tmp_n = 0;
	return (cnt);
}
