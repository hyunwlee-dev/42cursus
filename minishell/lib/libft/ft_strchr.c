/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:22:16 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == n)
		return ((char *)(str + i));
	return ((char *)0);
}
*/
char	*ft_strchr(const char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == n)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
