/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:44 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 02:14:56 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_map_tmp_row_column(t_map *map)
{
	int idx;
	int jdx;

	idx = 1;
	jdx = 0;
	map->tmp_row = (int)get_partitions(map->buf_safe, '\n');
	map->map = ft_split(map->buf_safe, '\n');
	map->tmp_column = (int)ft_strlen(map->map[0]);
	while (idx < map->tmp_row)
	{
		if (map->tmp_column < (int)ft_strlen(map->map[idx]))
			map->tmp_column = (int)ft_strlen(map->map[idx]);
		idx++;
	}
	map->tmp_row += 2;
	map->tmp_column += 2;
}

char	**allocate_map_tmp(t_map map)
{
	char	**result;
	int		idx;
	int		jdx;

	idx = 0;
	jdx = 0;
	if (!(result = (char **)malloc(sizeof(char *) * (map.tmp_row + 1))))
		return (NULL);
	result[map.tmp_row] = 0;
	while (idx < map.tmp_row)
	{
		if (!(result[idx] = (char *)malloc(sizeof(char) \
						* (map.tmp_column + 1))))
		{
			free_arrays(result, idx);
			return (NULL);
		}
		result[idx][map.tmp_column] = '\0';
		idx++;
	}
	return (result);
}

void	init_map_tmp(t_map *map)
{
	int	idx;

	idx = 0;
	while (idx < map->tmp_row)
	{
		ft_memset(map->map_tmp[idx], 'X', map->tmp_column);
		idx++;
	}
}

void	update_map_tmp(t_map *map)
{
	int	idx;
	int	jdx;

	idx = 0;
	while (idx < (int)get_partitions(map->buf_safe, '\n'))
	{
		jdx = 0;
		while (jdx < (int)ft_strlen(map->map[idx]))
		{
			if (map->map[idx][jdx] != ' ')
				map->map_tmp[idx + 1][jdx + 1] = map->map[idx][jdx];
			jdx++;
		}
		idx++;
	}
}

int		parse_map(t_map *map)
{
	get_map_tmp_row_column(map);
	if (!(map->map_tmp = allocate_map_tmp(*map)) || check_correct_inside(map))
	{
		printf("[Map Parsing]ALLOCATED FAIL!! || \
				IS NOT '0' OR '1' OR '2' OR 'N' IN MAP\n");
		return (1);
	}
	init_map_tmp(map);
	update_map_tmp(map);
	return (0);
}
