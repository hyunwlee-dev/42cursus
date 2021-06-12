/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:20:06 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:05:00 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(t_op op, unsigned int n)
{
	int		cnt;
	char	*tmp_hex;
	char	*tmp_n;

	cnt = 0;
	if (op.is_precision && (op.precision <= 0) && n == 0)
		tmp_n = ft_strdup("");
	else
	{
		if (!(tmp_hex = (char *)malloc(sizeof(char) * (get_hex_size(n) + 1))))
			return (0);
		*(tmp_hex + get_hex_size(n)) = '\0';
		treat_to_hex(op, n, &tmp_hex, 0);
		reverse_str(&tmp_hex);
		tmp_n = treat_precision_n(op, tmp_hex);
	}
	cnt += treat_width_n(op, tmp_n);
	free(tmp_n);
	tmp_n = 0;
	return (cnt);
}

int	print_addr(t_op op, void *addr)
{
	int				cnt;
	unsigned long	temp;
	char			*tmp_hex;
	char			*tmp_n;

	cnt = 0;
	temp = (unsigned long)addr;
	if (op.is_precision && (op.precision <= 0) && temp == 0)
		tmp_n = ft_strdup("");
	else
	{
		if (!(tmp_hex = (char *)malloc(sizeof(char) * (get_hex_size(temp) \
							+ 1))))
			return (0);
		*(tmp_hex + get_hex_size(temp)) = '\0';
		treat_to_hex(op, temp, &tmp_hex, 0);
		reverse_str(&tmp_hex);
		tmp_n = treat_precision_n(op, tmp_hex);
	}
	cnt += treat_width_n(op, tmp_n);
	free(tmp_n);
	tmp_n = 0;
	return (cnt);
}
