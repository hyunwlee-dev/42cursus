/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:33:04 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:45:14 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int treat_width_c(t_options op)
{
    int cnt;
    int idx;

    cnt = 0;
    idx = op.width - 1;
    while (idx-- > 0)
    {
        if (op.zero)
            cnt += ft_putchar_fd('0', 1);
        else
            cnt += ft_putchar_fd(' ', 1);
    }
    return (cnt);
}

int treat_width_s(t_options op, char **tmp_s)
{
    int cnt;
    int idx;

    cnt = 0;
    if (op.width <= (int)ft_strlen(*tmp_s))
    {
        ft_putstr_fd(*tmp_s, 1);
        return (ft_strlen(*tmp_s));
    }
    idx = op.width - ft_strlen(*tmp_s);
    if (op.minus == 1)
    {
        cnt += ft_putstr_fd(*tmp_s, 1);
        while (idx > 0)
        {
            if (op.zero == 1)
                cnt += ft_putchar_fd('0', 1);
            else
                cnt += ft_putchar_fd(' ', 1);
            idx--;
        }
    }
    else
    {
        while (idx > 0)
        {
            if (op.zero == 1)
                cnt += ft_putchar_fd('0', 1);
            else
                cnt += ft_putchar_fd(' ', 1);
            idx--;
        }
        cnt += ft_putstr_fd(*tmp_s, 1);
    }
    return (cnt);
}


int treat_width_n(t_options op, char **tmp_n)
{
    int cnt;
    int idx;

    cnt = 0;
    if (op.width <= (int)ft_strlen(*tmp_n))
    {
        ft_putstr_fd(*tmp_n, 1);
        return (ft_strlen(*tmp_n));
    }
    idx = op.width - ft_strlen(*tmp_n);

    if (op.minus == 1)
    {
        cnt += ft_putstr_fd(*tmp_n, 1);
        while (idx > 0)
        {
            if (op.precision == 0 && op.zero == 1)
                cnt += ft_putchar_fd('0', 1);
            else
                cnt += ft_putchar_fd(' ', 1);
            idx--;
        }
    }
    else
    {
        while (idx > 0)
        {
            if (op.precision == 0 && op.zero == 1)
                cnt += ft_putchar_fd('0', 1);
            else
                cnt += ft_putchar_fd(' ', 1);
            idx--;
        }
        cnt += ft_putstr_fd(*tmp_n, 1);
    }
    return (cnt);
}
