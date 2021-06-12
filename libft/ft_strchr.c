/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:18:56 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:42:32 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_tmp;

	s_tmp = (char *)s;
	while (*s_tmp && *s_tmp != (char)c)
		s_tmp++;
	if (*s_tmp == (char)c)
		return (s_tmp);
	return (NULL);
}
