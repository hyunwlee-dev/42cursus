/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:03 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:44:54 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_c(t_options op, int c)
{
    int cnt;

    cnt = 0;
    if (op.minus == 1)
    {
        cnt += ft_putchar_fd(c, 1);
        cnt += treat_width_c(op);
    }
    else
    {
        cnt += treat_width_c(op);
        cnt += ft_putchar_fd(c, 1);
    }
    return (cnt);
}
