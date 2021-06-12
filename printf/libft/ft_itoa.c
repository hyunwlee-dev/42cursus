/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:34:11 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:47 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	get_size(long nbr)
{
	long	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(long nbr)
{
	char	*result;
	int		len;
	int		i;
	long	tmp;

	tmp = nbr;
	len = (int)get_size(tmp);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	*(result + len) = '\0';
	if (tmp < 0)
	{
		*(result + i) = '-';
		tmp *= -1;
	}
	else if (tmp == 0)
		*(result + i) = '0';
	while (tmp != 0)
	{
		*(result + (--len)) = tmp % 10 + '0';
		tmp /= 10;
	}
	return (result);
}
