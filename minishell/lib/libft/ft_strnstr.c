/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:38:52 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:14 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)&str[i]);
	if (!str)
		return ((char *)0);
	while (str[i])
	{
		if (len < ft_strlen(to_find))
			break ;
		if (ft_strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
		{
			return ((char *)(str + i));
		}
		i++;
		len--;
	}
	return ((char *)0);
}
