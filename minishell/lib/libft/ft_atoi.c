/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 07:05:37 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_overflow_int(int sign, unsigned int u_num)
{
	if (sign == 1 && u_num > 0x7fffffff)
		return (-1);
	else if (sign == -1 && u_num > 0x80000000)
		return (0);
	return (1);
}

static	void	norm(unsigned char **u_str)
{
	while (**u_str == '\t' || **u_str == '\v' || **u_str == '\n'
		|| **u_str == '\r' || **u_str == '\f' || **u_str == ' ')
		*u_str = *u_str + 1;
}

int	ft_atoi(const char *str)
{
	unsigned char	*u_str;
	int				sign;
	unsigned int	u_num;
	int				res;

	u_str = (unsigned char *)str;
	norm(&u_str);
	sign = 1;
	if (*u_str == '-' || *u_str == '+')
	{
		if (*u_str == '-')
			sign *= -1;
		u_str++;
	}
	u_num = 0;
	while (ft_isdigit(*u_str))
	{
		u_num = (u_num * 10) + (*u_str - '0');
		res = ft_check_overflow_int(sign, u_num);
		if (res != 1)
			return (res);
		u_str++;
	}
	return (sign * u_num);
}
