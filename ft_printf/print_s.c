/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:20:19 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/27 15:46:07 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(t_op op, char *s)
{
	int		cnt;
	char	*tmp_s;

	cnt = 0;
	if (s == NULL)
		tmp_s = ft_strdup("(null)");
	else
		tmp_s = ft_strdup(s);
	if (op.is_precision && op.precision < (int)ft_strlen(tmp_s))
	{
		if (!(tmp_s = treat_precision_s(op, tmp_s)))
			return (cnt);
	}
	cnt += treat_width_s(op, tmp_s);
	free(tmp_s);
	tmp_s = 0;
	return (cnt);
}
