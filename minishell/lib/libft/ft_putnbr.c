/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:52:38 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:14 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int number)
{
	if (number < 0)
	{
		print_char('-');
		if (number == -2147483648)
		{
			ft_putnbr((number / 10) * -1);
			print_char('8');
		}
		else
		{
			ft_putnbr(number * -1);
		}
	}
	else
	{
		if (number > 9)
		{
			ft_putnbr(number / 10);
			print_char((number % 10) + 48);
		}
		else
		{
			print_char(number + 48);
		}
	}
}
