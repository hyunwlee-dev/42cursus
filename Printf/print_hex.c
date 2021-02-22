/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:13 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:44:58 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hex(t_options op, unsigned int n)
{
    int cnt;
    char *tmp_hex_s;
    char *tmp_n;

    cnt = 0;
    tmp_hex_s = ft_strdup("");
    tmp_n = ft_strdup("");
    treat_to_hex(op, n, tmp_hex_s);
    treat_precision_n(op, &tmp_n, tmp_hex_s, 1);
    cnt += treat_width_n(op, &tmp_n);
    free(tmp_hex_s);
    free(tmp_n);
    tmp_hex_s = 0;
    tmp_n = 0;
    return (cnt);
}

int print_addr(t_options op, void *ptr)
{
    unsigned long long temp;
    temp = (unsigned long long) ptr;

    int cnt;
    char *tmp_hex_s;
    char *tmp_n;

    cnt = 0;
    tmp_hex_s = ft_strdup("");
    treat_to_hex(op, temp, tmp_hex_s);
    tmp_n = ft_strdup("");
    treat_precision_n(op, &tmp_n, tmp_hex_s, 1);
    cnt += treat_width_n(op, &tmp_n);
    free(tmp_hex_s);
    free(tmp_n);
    tmp_hex_s = 0;
    tmp_n = 0;
    return (cnt);
}
