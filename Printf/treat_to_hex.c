/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:58 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 18:45:12 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_to_hex(t_options op, unsigned int n, char *ans)
{
    char *arr;

    if (op.type == 'X')
        arr = "0123456789ABCDEF";
    else
        arr = "0123456789abcdef";
    if (n >= 0 && n < 16)
        ans = ft_strjoin(ans, arr[n]);
    else if (n >= 16)
    {
        ans = treat_to_hex(op, n / 16, ans);
        ans = ft_strjoin(ans, arr[n % 16]);
    }
	return (ans);
}
