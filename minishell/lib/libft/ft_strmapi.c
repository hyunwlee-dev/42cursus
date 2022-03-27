/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:09:54 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	i = 0;
	if (s && f)
	{
		tmp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[ft_strlen(s)] = 0x00;
		while (s[i])
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
