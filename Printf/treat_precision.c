/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:32:52 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/21 19:07:05 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     treat_precision_s(t_options op, char *str, char **tmp_s)
{
    free(*tmp_s);
    *tmp_s = 0;
    if (!(*tmp_s = (char *)malloc(sizeof(char) * (op.precision + 1))))
        return (0);
    ft_strlcpy(*tmp_s, str, op.precision + 1);
    return (1);
}

int treat_precision_n(t_options op, char **tmp_n, char *n, int sign)
{
    int len;
    int idx;
    
    free(*tmp_n);
    *tmp_n = 0;
    if (op.precision <= (int)ft_strlen(n))
    {
        if (sign == -1)
        {
            idx = 1;
            if (!(*tmp_n = (char *) malloc(sizeof(char) * (ft_strlen(n) + 1 + 1))))
				return (0);
            **tmp_n = '-';
            ft_strlcpy((*tmp_n + idx), n, ft_strlen(n) + 1 + 1);
        }
        else
        {
            if (op.type == 'p')
            {
                idx = 0;
                if (!(*tmp_n = (char *) malloc(sizeof(char) * (ft_strlen(n) + 1 + 2))))
					return (0);
                *(*tmp_n + idx++) = '0';
                *(*tmp_n + idx++) = 'x';
                ft_strlcpy((*tmp_n + idx), n, ft_strlen(n) + 1 + 2);
            }
            else
                *tmp_n = ft_strdup(n);
        }
        return (1);
    }
    len = op.precision - ft_strlen(n);
    if (sign == -1)
    {
        idx = 1;
        if (!(*tmp_n = (char *) malloc(sizeof(char) * (op.precision + 1 + 1))))
			return (0);
        **tmp_n = '-';
        while (len-- > 0)
            *(*tmp_n + idx++) = '0';
        ft_strlcpy((*tmp_n + idx), n, op.precision + 1 + 1);
    }
    else
    {
        idx = 0;
        if (op.type == 'p')
        {
            if (!(*tmp_n = (char *) malloc(sizeof(char) * (ft_strlen(n) + 1 + 2))))
				return (0);
            *(*tmp_n + idx++) = '0';
            *(*tmp_n + idx++) = 'x';
            while (len-- > 0)
                *(*tmp_n + idx++) = '0';
            ft_strlcpy((*tmp_n + idx), n, op.precision + 1 + 2);
        }
        else
        {
            if (!(*tmp_n = (char *) malloc(sizeof(char) * (op.precision + 1))))
                return (0);
            while (len-- > 0)
                *(*tmp_n + idx++) = '0';
            ft_strlcpy((*tmp_n + idx), n, op.precision + 1);
        }
    }
    return (1);
}
