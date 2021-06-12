/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:47 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/02 20:45:31 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	get_partitions(char *s, char c)
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

int		check_alnum_str(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx))
	{
		if (ft_isalnum(*(str + idx)))
			return (1);
		idx++;
	}
	return (0);
}

void	free_array(t_map *map)
{
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free(map->buf_safe);
}

void	free_arrays(char **str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
		free(str[idx++]);
	free(str);
}

void	free_arrays_integers(int **arr, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
		free(arr[idx++]);
	free(arr);
}
