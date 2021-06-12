/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:04:20 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/02 20:42:36 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_floor(char **str, t_map **map)
{
	char	**arr;
	int		idx;
	int		jdx;

	idx = 0;
	if ((int)get_partitions(str[1], ',') != 3)
		return (1);
	arr = ft_split(str[1], ',');
	while (idx < (int)get_partitions(str[1], ','))
	{
		jdx = 0;
		while (arr[idx][jdx] != '\0' && ft_isdigit(arr[idx][jdx]))
			jdx++;
		if (arr[idx][jdx] != '\0' && !ft_isdigit(arr[idx][jdx]))
			return (1);
		idx++;
	}
	(*map)->f[0] = ft_atoi(arr[0]);
	(*map)->f[1] = ft_atoi(arr[1]);
	(*map)->f[2] = ft_atoi(arr[2]);
	(*map)->check.f = 1;
	free_arrays(arr, (int)get_partitions(str[1], ','));
	return (0);
}

int	check_ceil(char **str, t_map **map)
{
	char	**arr;
	int		idx;
	int		jdx;

	if ((int)get_partitions(str[1], ',') != 3)
		return (1);
	arr = ft_split(str[1], ',');
	idx = 0;
	while (idx < (int)get_partitions(str[1], ','))
	{
		jdx = 0;
		while (arr[idx][jdx] != '\0' && ft_isdigit(arr[idx][jdx]))
			jdx++;
		if (arr[idx][jdx] != '\0' && !ft_isdigit(arr[idx][jdx]))
			return (1);
		idx++;
	}
	(*map)->c[0] = ft_atoi(arr[0]);
	(*map)->c[1] = ft_atoi(arr[1]);
	(*map)->c[2] = ft_atoi(arr[2]);
	(*map)->check.c = 1;
	free_arrays(arr, (int)get_partitions(str[1], ','));
	return (0);
}

int	check_floor_ceil(char **str, int cnt, t_map **map)
{
	if (cnt != 2)
		return (0);
	if (!ft_strncmp(str[0], "F", 2))
	{
		if (check_floor(str, map))
			return (0);
	}
	else if (!ft_strncmp(str[0], "C", 2))
	{
		if (check_ceil(str, map))
			return (0);
	}
	return (1);
}
