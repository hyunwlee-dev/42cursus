/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:46:32 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*tmp;
	const char		*s;

	tmp = dest;
	s = src;
	if (dest <= src)
	{
		return (ft_memcpy(dest, src, count));
	}
	else
	{
		tmp = tmp + count;
		s = s + count;
		while (count--)
			*--tmp = *--s;
	}
	return (dest);
}
