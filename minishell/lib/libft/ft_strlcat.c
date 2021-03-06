/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:39:00 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:14 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dst;
	const char		*src_start;
	unsigned int	dest_len;
	unsigned int	copy_size;

	dst = dest;
	src_start = src;
	copy_size = size;
	while (copy_size-- != 0 && *dst != '\0')
		dst++;
	dest_len = dst - dest;
	copy_size = size - dest_len;
	if (copy_size == 0)
		return (dest_len + ft_strlen(src));
	while (*src != '\0')
	{
		if (copy_size > 1)
		{
			*dst++ = *src;
			copy_size--;
		}
		src++;
	}
	*dst = '\0';
	return (dest_len + (src - src_start));
}
