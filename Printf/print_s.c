/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:46 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:45:06 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_s(t_options op, char *str)
{
    int cnt;
    char *tmp_s;

    cnt = 0;
    tmp_s = (str != NULL) ? ft_strdup(str) : ft_strdup("(null)");
    if (op.is_precision == 1 && op.precision < (int)ft_strlen(str))
        treat_precision_s(op, str, &tmp_s);
    if (op.minus == 1 && op.zero == 1)
        op.zero = 0;
    cnt += treat_width_s(op, &tmp_s);
    free(tmp_s);
    tmp_s = 0;
    return (cnt);
}
