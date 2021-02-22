/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:21:26 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:47 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	if (!dst && !src)
		return (NULL);
	while (len--)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src);
		if (*((unsigned char *)src++) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
