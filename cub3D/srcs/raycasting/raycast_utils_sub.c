/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:26:21 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 02:26:20 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

void	init_buf(t_cub *cub)
{
	t_info	*info_ptr;
	int		idx;
	int		jdx;

	idx = 0;
	info_ptr = &(cub->info);
	while (idx < HEIGHT)
	{
		jdx = 0;
		while (jdx < WIDTH)
		{
			info_ptr->buf[idx][jdx] = 0;
			jdx++;
		}
		idx++;
	}
}

void	init_texture(t_cub *cub)
{
	t_info	*info_ptr;
	int		idx;
	int		jdx;

	info_ptr = &(cub->info);
	idx = 0;
	while (idx < 4)
	{
		jdx = 0;
		while (jdx < TEXHEIGHT * TEXWIDTH)
		{
			info_ptr->texture[idx][jdx] = 0;
			jdx++;
		}
		idx++;
	}
}

void	init_worldmap(t_cub *cub)
{
	t_info	*info_ptr;
	int		idx;
	int		jdx;

	idx = 0;
	info_ptr = &(cub->info);
	while (idx < cub->map.tmp_row)
	{
		jdx = 0;
		while (jdx < cub->map.tmp_column)
		{
			if (cub->map.map_tmp[idx][jdx] == 'X')
				info_ptr->worldmap[idx][jdx] = 1;
			else if (cub->map.map_tmp[idx][jdx] == 'N')
				info_ptr->worldmap[idx][jdx] = 0;
			else
				info_ptr->worldmap[idx][jdx] = cub->map.map_tmp[idx][jdx] - '0';
			jdx++;
		}
		idx++;
	}
}
