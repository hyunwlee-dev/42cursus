/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 18:56:22 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:47 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*b1_tmp;
	unsigned char	*b2_tmp;

	if (!len)
		return (0);
	b1_tmp = (unsigned char *)b1;
	b2_tmp = (unsigned char *)b2;
	while (len--)
	{
		if (*b1_tmp != *b2_tmp)
			return (*b1_tmp - *b2_tmp);
		b1_tmp++;
		b2_tmp++;
	}
	return (0);
}
