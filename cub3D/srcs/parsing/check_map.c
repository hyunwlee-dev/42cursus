/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:37 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/02 20:43:27 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_correct_inside(t_map *map)
{
	int	idx;
	int	jdx;
	int	flag;

	idx = 0;
	flag = 0;
	while (idx < (int)get_partitions(map->buf_safe, '\n'))
	{
		jdx = 0;
		while (jdx < (int)ft_strlen(map->map[idx]))
		{
			if (check_player_position(map, &flag, idx, jdx))
				return (1);
			jdx++;
		}
		idx++;
	}
	if (!flag)
		return (1);
	return (0);
}

void	init_bfs(t_map *map, t_bfs *bfs)
{
	(&(bfs->q))->front = 0;
	(&(bfs->q))->rear = 0;
	(&(bfs->p))->x = map->player_x;
	(&(bfs->p))->y = map->player_y;
	offer((&(bfs->q)), (bfs->p));
	bfs->check[(&(bfs->p))->x][(&(bfs->p))->y] = 1;
}

int		sub_bfs(t_map *map, t_bfs *bfs, int next_x, int next_y)
{
	if (map->map_tmp[next_x][next_y] == 'X')
	{
		printf("[Map Parsing]MAP IS NOT SURROUNDED BY WALLS\n");
		return (1);
	}
	bfs->check[next_x][next_y] = 1;
	(&(bfs->p))->x = next_x;
	(&(bfs->p))->y = next_y;
	offer((&(bfs->q)), (bfs->p));
	return (0);
}

int		main_bfs(t_map *map, t_bfs *bfs)
{
	const int	dx[4] = {0, 0, 1, -1};
	const int	dy[4] = {1, -1, 0, 0};
	int			next_x;
	int			next_y;
	int			idx;

	idx = 0;
	while (idx < 4)
	{
		next_x = (&(bfs->p_now))->x + dx[idx];
		next_y = (&(bfs->p_now))->y + dy[idx];
		if (bfs->check[next_x][next_y] == 0 && \
				(0 <= next_x && next_x < map->tmp_row) \
				&& (0 <= next_y && next_y < map->tmp_column) \
				&& map->map_tmp[next_x][next_y] != '1' \
				&& map->map_tmp[next_x][next_y] != '2')
			if (sub_bfs(map, bfs, next_x, next_y))
				return (1);
		idx++;
	}
	return (0);
}

int		check_map_bfs(t_map *map, t_bfs *bfs)
{
	t_queue		*q;
	t_position	*p;
	t_position	*p_now;

	q = &(bfs->q);
	p = &(bfs->p);
	p_now = &(bfs->p_now);
	init_bfs(map, bfs);
	while (!is_empty(q))
	{
		*p_now = poll(q);
		if (main_bfs(map, bfs))
			return (1);
	}
	free_arrays_integers(bfs->check, map->tmp_row);
	return (0);
}
