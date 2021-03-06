/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:37:51 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:14 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s2[i] == 0x00 || s1[i] == 0x00)
		{
			return (0);
		}
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s2[i] == s1[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
