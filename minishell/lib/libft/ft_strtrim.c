/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:11:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left(const char *s, const char *delset)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(delset, s[i]) == (char *)0)
			break ;
		i++;
	}
	return (i);
}

static int	get_right(const char *s, const char *delset)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i)
	{
		if (ft_strchr(delset, s[i]) == (char *)0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s, const char *delset)
{
	char	*tmp;
	size_t	i;
	size_t	left;
	size_t	right;

	left = get_left(s, delset);
	if (left == ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	right = get_right(s, delset);
	i = ft_strlen(s) - 1 - right;
	tmp = ft_substr(s, left, ft_strlen(s) - left - i);
	return (tmp);
}
