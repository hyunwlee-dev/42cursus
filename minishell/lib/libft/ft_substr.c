/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:48:27 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp || s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	tmp[len] = 0x00;
	while (len && s[start])
	{
		tmp[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (tmp);
}
