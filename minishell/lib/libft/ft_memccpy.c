/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:13:38 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sc;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		dst[i] = sc[i];
		if (dst[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
