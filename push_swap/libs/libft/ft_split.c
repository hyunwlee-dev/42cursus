/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:41:33 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/09/23 19:11:18 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
			++cnt;
		while (*(s + i) != c && *(s + i))
			++i;
		if (*(s + i) == c)
			++i;
	}
	return (cnt);
}

static void	str_cpy(char *dst, const char *src, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end - start)
	{
		*(dst + i) = *(src + start + i);
		i++;
	}
	*(dst + i) = '\0';
}

static void	free_mal(char **tmp, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(tmp[i++]);
	free(tmp);
}

static int	sub_split(char **tmp, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		k = i;
		if (*(str + i) == c)
		{
			i++;
			continue ;
		}
		while (*(str + i) != c && *(str + i))
			i++;
		tmp[j] = (char *)malloc(sizeof(char) * (i - k + 1));
		if (!tmp[j])
		{
			free_mal(tmp, j);
			return (1);
		}
		str_cpy(tmp[j++], str, k, i);
	}
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**tmp;
	size_t	len;

	len = get_len(str, c);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[len] = 0;
	if (sub_split(tmp, str, c))
		return (NULL);
	return (tmp);
}
