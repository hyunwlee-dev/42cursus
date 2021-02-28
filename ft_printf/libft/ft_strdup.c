/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:31:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/02/27 15:24:23 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strdup(char *str)
{
	char	*tmp;
	int		idx;

	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (*str)
		*(tmp + (idx++)) = *(str++);
	*(tmp + idx) = '\0';
	return (tmp);
}
