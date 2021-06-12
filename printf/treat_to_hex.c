/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:21:19 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/26 03:28:34 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	treat_to_hex(t_op op, unsigned long n, char **tmp_hex, int idx)
{
	const char *arr;

	if (op.type == 'x' || op.type == 'p')
		arr = "0123456789abcdef";
	else
		arr = "0123456789ABCDEF";
	if (n >= 0 && n < 16)
		*(*tmp_hex + idx) = arr[n];
	else if (n >= 16)
	{
		treat_to_hex(op, n / 16, tmp_hex, idx + 1);
		*(*tmp_hex + idx) = arr[n % 16];
	}
}
