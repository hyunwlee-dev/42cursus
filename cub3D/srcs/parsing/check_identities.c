/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:07:18 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 02:14:14 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	free_situatioin_terminate(char *s, char **str, int size)
{
	if (!(ft_strncmp(s, "texture", ft_strlen(s))))
		printf("[Map Parsing]TEXTURE ERROR!!\n");
	else if (!(ft_strncmp(s, "floor||ceiling", ft_strlen(s))))
		printf("[Map Parsing]FLOOR CEILING ERROR!!\n");
	else if (!(ft_strncmp(s, "else", ft_strlen(s))))
		printf("[Map Parsing]NOT NEEDED ID INSERTED!!\n");
	else if (!(ft_strncmp(s, "map", ft_strlen(s))))
		printf("[Map Parsing]VALIDATION IDENTITIES ERROR!! \
				OR MAP SEQUENCE ERROR!!\n");
	free_arrays(str, size);
	return (1);
}

int	check_validation_identities(t_map map)
{
	if (!map.check.no || !map.check.so || \
			!map.check.we || !map.check.ea || !map.check.f || !map.check.c)
		return (0);
	return (1);
}

int	check_identities(char *line, t_map *map, char **str)
{
	if (*line && ft_isalpha(str[0][0]))
	{
		if (check_texture_floor_ceil(line, map, str))
			return (1);
	}
	else if (*line)
	{
		if (!check_validation_identities(*map) \
				|| !(map->buf_safe = gnl_strjoin(&(map->buf_safe), line)) \
				|| !(map->buf_safe = gnl_strjoin(&(map->buf_safe), "\n")))
			return (free_situatioin_terminate("map", str, \
						(int)get_partitions(line, ' ')));
	}
	return (0);
}

int	check_texture_floor_ceil(char *line, t_map *map, char **str)
{
	if (!ft_strncmp(str[0], "NO", 3) || !ft_strncmp(str[0], "SO", 3) \
			|| !ft_strncmp(str[0], "WE", 3) || !ft_strncmp(str[0], "EA", 3))
	{
		if (!(check_texture(str, (int)get_partitions(line, ' '), &map)))
			return (free_situatioin_terminate("texture", str, \
						(int)get_partitions(line, ' ')));
	}
	else if (!ft_strncmp(str[0], "F", 2) || !ft_strncmp(str[0], "C", 2))
	{
		if (!(check_floor_ceil(str, (int)get_partitions(line, ' '), &map)))
			return (free_situatioin_terminate("floor||ceiling", str, \
						(int)get_partitions(line, ' ')));
	}
	else
	{
		return (free_situatioin_terminate("else", str, \
					(int)get_partitions(line, ' ')));
	}
	return (0);
}

int	check_player_position(t_map *map, int *flag, int idx, int jdx)
{
	char	c;

	c = map->map[idx][jdx];
	if (*flag && c == 'N')
		return (1);
	if (c == 'N')
	{
		*flag = 1;
		map->player_x = idx + 1;
		map->player_y = jdx + 1;
	}
	if (c != ' ' && c != '0' && c != '1' && c != 'N')
		return (1);
	return (0);
}
