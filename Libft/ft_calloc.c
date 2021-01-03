/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:31:20 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:40:47 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(number * size)))
		return (NULL);
	ft_bzero(tmp, number * size);
	return (tmp);
}
