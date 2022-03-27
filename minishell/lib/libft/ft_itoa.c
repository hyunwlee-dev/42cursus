/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:39:12 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int	count;

	if (n == 0)
		return (2);
	count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static	void	norm(int n, int *len, char **arr)
{
	*len = ft_nbrlen(n);
	*arr = (char *)malloc(*len * sizeof(char));
	(*arr)[*len - 1] = 0x00;
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;

	norm(n, &len, &arr);
	len--;
	if (n < 0)
	{
		arr[0] = '-';
		while (len-- > 1)
		{
			arr[len] = '0' - (n % 10);
			n = n / 10;
		}
	}
	else
	{
		while (len--)
		{
			arr[len] = '0' + (n % 10);
			n = n / 10;
		}
	}
	return (arr);
}
