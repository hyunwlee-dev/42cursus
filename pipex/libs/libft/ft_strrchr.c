/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:31:16 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:42:32 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_tmp;

	s_tmp = (char *)s;
	while (*(s_tmp++))
		;
	while ((--s_tmp != s) && (*s_tmp != (char)c))
		;
	if (*s_tmp == (char)c)
		return (s_tmp);
	return (NULL);
}
