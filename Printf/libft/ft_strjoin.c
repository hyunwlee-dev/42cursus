/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:59:38 by hyunwlee          #+#    #+#             */
/*   Updated: 2020/12/30 16:42:32 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char *s, char c)
{
    char    *tmp;
    char	*start;
	size_t  len;
    size_t  i;

	start = s;
    len = ft_strlen(s) + 1;
    if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (*s)
        *(tmp + i++) = *(s++);
    *(tmp + i++) = c;
    *(tmp + i) = '\0';
	free(start);
	start = 0;
    return (tmp);
}
