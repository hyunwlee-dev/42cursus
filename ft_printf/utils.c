/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 02:21:30 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/26 03:29:08 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int					ft_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		write(1, str, 1);
		str++;
		cnt++;
	}
	return (cnt);
}

void				reverse_str(char **str)
{
	int		idx;
	char	tmp;

	idx = 0;
	while (idx < (int)ft_strlen(*str) / 2)
	{
		tmp = *(*str + idx);
		*(*str + idx) = *(*str + ((int)ft_strlen(*str) - 1 - idx));
		*(*str + ((int)ft_strlen(*str) - 1 - idx)) = tmp;
		idx++;
	}
}

unsigned long		get_hex_size(unsigned long n)
{
	unsigned long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}
