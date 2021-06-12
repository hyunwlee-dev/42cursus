/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 02:24:41 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:06:08 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

void	key_press_no_so(t_info *info, t_dir *dir)
{
	dir->sign = (info->key_w) ? 1 : -1;
	dir->new_x = info->pos_x + info->dir_x * info->movespeed * dir->sign;
	dir->new_y = info->pos_y + info->dir_y * info->movespeed * dir->sign;
	if (info->worldmap[(int)(dir->new_x)][(int)info->pos_y] == 0)
		info->pos_x = dir->new_x;
	if (info->worldmap[(int)info->pos_x][(int)(dir->new_y)] == 0)
		info->pos_y = dir->new_y;
}

void	key_press_we_ea(t_info *info, t_dir *dir)
{
	dir->sign = (info->key_a) ? 1 : -1;
	dir->new_x = info->pos_x - info->dir_y * info->movespeed * dir->sign;
	dir->new_y = info->pos_y + info->dir_x * info->movespeed * dir->sign;
	if (info->worldmap[(int)(dir->new_x)][(int)info->pos_y] == 0)
		info->pos_x = dir->new_x;
	if (info->worldmap[(int)info->pos_x][(int)(dir->new_y)] == 0)
		info->pos_y = dir->new_y;
}

void	key_press_left_right(t_info *info, t_dir *dir)
{
	dir->angle = (info->key_left) ? info->rotatespeed : -1 * info->rotatespeed;
	dir->old_dir_x = info->dir_x;
	dir->old_plane_x = info->plane_x;
	info->dir_x = cos(dir->angle) * info->dir_x - sin(dir->angle) * info->dir_y;
	info->dir_y = sin(dir->angle) * dir->old_dir_x + cos(dir->angle) \
			* info->dir_y;
	info->plane_x = cos(dir->angle) * \
		info->plane_x - sin(dir->angle) * info->plane_y;
	info->plane_y = sin(dir->angle) * \
		dir->old_plane_x + cos(dir->angle) * info->plane_y;
}
