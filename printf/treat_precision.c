/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:20:31 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/28 01:22:22 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_precision_s(t_op op, char *tmp_s)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (op.precision + 1))))
		return (0);
	ft_strlcpy(str, tmp_s, op.precision + 1);
	free(tmp_s);
	return (str);
}

char	*treat_precision_n(t_op op, char *n)
{
	int		len;
	int		idx;
	char	*tmp_n;

	idx = 0;
	len = (op.precision > (int)ft_strlen(n)) ? op.precision : (int)ft_strlen(n);
	if (!(tmp_n = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (op.is_precision && op.precision > (int)ft_strlen(n) \
			&& idx < op.precision - (int)ft_strlen(n))
		*(tmp_n + idx++) = '0';
	ft_strlcpy(tmp_n + idx, n, len + 1);
	return (tmp_n);
}
