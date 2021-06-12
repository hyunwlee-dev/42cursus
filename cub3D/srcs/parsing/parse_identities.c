/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:42 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:20:41 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_texture_floor_ceil(char *line, t_map *map)
{
	char	**str;

	str = ft_split(line, ' ');
	if (check_identities(line, map, str))
		return (1);
	free_arrays(str, (int)get_partitions(line, ' '));
	return (0);
}

void	init_identities(t_map *map)
{
	map->no = ft_strdup("");
	map->so = ft_strdup("");
	map->we = ft_strdup("");
	map->ea = ft_strdup("");
	ft_bzero(&(map->f), sizeof(map->f));
	ft_bzero(&(map->c), sizeof(map->c));
	map->map = 0;
	map->map_tmp = 0;
	map->buf_safe = ft_strdup("");
	map->tmp_row = 0;
	map->tmp_column = 0;
	map->player_x = 0;
	map->player_y = 0;
	ft_bzero(&(map->check), sizeof(map->check));
}

int		**allocate_check(t_map map)
{
	int	**result;
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	if (!(result = (int **)malloc(sizeof(int *) * (map.tmp_row))))
		return (NULL);
	while (idx < map.tmp_row)
	{
		if (!(result[idx] = (int *)malloc(sizeof(int) * (map.tmp_column))))
		{
			free_arrays_integers(result, idx);
			return (NULL);
		}
		idx++;
	}
	return (result);
}

int		treat_map(t_map *map)
{
	t_bfs	bfs;
	int		i;
	int		j;

	if (parse_map(map))
		return (1);
	if (!(bfs.check = allocate_check(*map)))
		return (1);
	i = -1;
	while (++i < map->tmp_row)
	{
		j = -1;
		while (++j < map->tmp_column)
			bfs.check[i][j] = 0;
	}
	if (check_map_bfs(map, &bfs))
		return (1);
	return (0);
}

int		parse_main(char *map_title, t_map *map)
{
	char	*title;
	char	*line;
	int		ret;
	int		fd;

	title = ft_strjoin("./map/", map_title);
	fd = open(title, O_RDONLY);
	free(title);
	if (fd == -1)
		return (1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (parse_texture_floor_ceil(line, map))
			return (1);
		free(line);
		line = 0;
	}
	if (parse_texture_floor_ceil(line, map))
		return (1);
	free(line);
	line = 0;
	close(fd);
	if (treat_map(map))
		return (1);
	return (0);
}
