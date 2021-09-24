/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 01:31:20 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 19:05:14 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*tmp;

	tmp = malloc(number * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, number * size);
	return (tmp);
}
