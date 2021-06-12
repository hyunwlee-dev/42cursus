/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:20 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/03/31 16:57:14 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s++))
		++cnt;
	return (cnt);
}

char	*gnl_substr(char **s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > gnl_strlen(*s))
		return (tmp);
	while (len-- && *((*s) + start + i))
	{
		*(tmp + i) = *((*s) + start + i);
		i++;
	}
	*(tmp + i) = '\0';
	free(*s);
	*s = 0;
	return (tmp);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*src_tmp;

	if (!dst && !src)
		return (0);
	src_tmp = (char *)src;
	if (dstsize > 0)
	{
		while (*src_tmp && --dstsize)
			*(dst++) = *(src_tmp++);
		*dst = '\0';
	}
	return (gnl_strlen(src));
}

char	*gnl_strdup(const char *str)
{
	char	*tmp;
	size_t	idx;

	idx = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (gnl_strlen(str) + 1))))
		return (NULL);
	while (*str)
		*(tmp + (idx++)) = *(str++);
	*(tmp + idx) = '\0';
	return (tmp);
}

char	*gnl_strjoin(char **s1, char const *s2)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	if (!(*s1) || !s2)
		return (NULL);
	len = gnl_strlen(*s1) + gnl_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*((*s1) + i))
	{
		*(tmp + i) = *((*s1) + i);
		i++;
	}
	while (*(s2))
		*(tmp + (i++)) = *(s2++);
	*(tmp + i) = '\0';
	free(*s1);
	*s1 = 0;
	return (tmp);
}
