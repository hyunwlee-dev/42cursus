/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:06:34 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:47 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*dst_tmp;

	if (!dst && !src)
		return (NULL);
	dst_tmp = (char *)dst;
	while (len--)
		*(dst_tmp++) = *((char *)(src++));
	return (dst);
}
