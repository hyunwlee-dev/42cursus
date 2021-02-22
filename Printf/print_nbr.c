/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:34 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:45:01 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_nbr(t_options op, int n)
{
    int cnt;
    int sign;
    char *tmp_n;

    cnt = 0;
    sign = 1;
    if (n < 0)
    {
        sign *= -1;
        n *= -1;
    }
	tmp_n = ft_strdup("");
	treat_precision_n(op, &tmp_n, ft_itoa(n), sign);
	cnt += treat_width_n(op, &tmp_n);
    free(tmp_n);
    tmp_n = 0;
    return (cnt);
}

int print_u_nbr(t_options op, unsigned int n)
{
    int cnt;
    char *tmp_n;

    cnt = 0;
    tmp_n = ft_strdup("");
    treat_precision_n(op, &tmp_n, ft_itoa(n), 1);
    cnt += treat_width_n(op, &tmp_n);
    free(tmp_n);
    tmp_n = 0;
    return (cnt);
}
