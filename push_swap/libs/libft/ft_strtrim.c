/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:47:00 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 19:15:46 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	int		flag;
	size_t	i;
	size_t	j;

	i = 0;
	while (*(s1 + i))
	{
		flag = 0;
		j = 0;
		while (*(set + j) && !flag)
		{
			if (*(s1 + i) == *(set + j))
				flag = 1;
			j++;
		}
		if (!flag)
			break ;
		i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	int		flag;
	size_t	i;
	size_t	j;
	char	*start;

	i = ft_strlen(s1) - 1;
	start = (char *)s1;
	while ((s1 + i) != start)
	{
		flag = 0;
		j = 0;
		while (*(set + j) && !flag)
		{
			if (*(s1 + i) == *(set + j))
				flag = 1;
			j++;
		}
		if (!flag)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end < start)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (end - start + 1 + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1 + start, end - start + 1 + 1);
	return (tmp);
}
