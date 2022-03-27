/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 02:22:16 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int			i;
	const char	*last;

	i = 0;
	last = NULL;
	while (str[i])
	{
		if (str[i] == n)
		{
			last = str + i;
		}
		i++;
	}
	if (str[i] == n)
		return ((char *)(str + i));
	if (last != NULL)
		return ((char *)last);
	return ((char *)0);
}
