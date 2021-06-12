/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:50 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:15:44 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"
#include "libft.h"

void	init_dda_sidedist(t_info *info_ptr, t_dda *dda)
{
	if (dda->raydir_x < 0)
	{
		dda->step_x = -1;
		dda->sidedist_x = (info_ptr->pos_x - dda->map_x) * dda->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedist_x = (dda->map_x + 1.0 - info_ptr->pos_x) \
					* dda->deltadist_x;
	}
	if (dda->raydir_y < 0)
	{
		dda->step_y = -1;
		dda->sidedist_y = (info_ptr->pos_y - dda->map_y) * dda->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedist_y = (dda->map_y + 1.0 - info_ptr->pos_y) \
					* dda->deltadist_y;
	}
}

void	init_dda_struct(t_info *info_ptr, t_dda *dda, int x)
{
	dda->hit = 0;
	dda->map_x = (int)(info_ptr->pos_x);
	dda->map_y = (int)(info_ptr->pos_y);
	dda->camera_x = 2 * x / (double)WIDTH - 1;
	dda->raydir_x = info_ptr->dir_x + info_ptr->plane_x * dda->camera_x;
	dda->raydir_y = info_ptr->dir_y + info_ptr->plane_y * dda->camera_x;
	dda->deltadist_x = fabs(1 / dda->raydir_x);
	dda->deltadist_y = fabs(1 / dda->raydir_y);
	init_dda_sidedist(info_ptr, dda);
}

void	find_hit_dda(t_info *info_ptr, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->sidedist_x < dda->sidedist_y)
		{
			dda->sidedist_x += dda->deltadist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedist_y += dda->deltadist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (info_ptr->worldmap[dda->map_x][dda->map_y] > 0)
			dda->hit = 1;
	}
}

void	get_draw_point(t_info *info_ptr, t_dda *dda)
{
	if (dda->side == 0)
		dda->perpwalldist = (dda->map_x - info_ptr->pos_x + \
				(1 - dda->step_x) / 2) / dda->raydir_x;
	else
		dda->perpwalldist = (dda->map_y - info_ptr->pos_y + \
				(1 - dda->step_y) / 2) / dda->raydir_y;
	dda->lineheight = (int)(HEIGHT / dda->perpwalldist);
	dda->drawstart = -dda->lineheight / 2 + HEIGHT / 2;
	if (dda->drawstart < 0)
		dda->drawstart = 0;
	dda->drawend = dda->lineheight / 2 + HEIGHT / 2;
	if (dda->drawend >= HEIGHT)
		dda->drawend = HEIGHT - 1;
}

int		raycaster(t_cub *cub)
{
	t_img	*img_ptr;
	t_info	*info_ptr;
	t_dda	dda;
	int		x;

	img_ptr = &(cub->img);
	info_ptr = &(cub->info);
	draw_background(cub);
	x = -1;
	while (++x < WIDTH)
	{
		init_dda_struct(info_ptr, &dda, x);
		find_hit_dda(info_ptr, &dda);
		get_draw_point(info_ptr, &dda);
		init_texture_struct(info_ptr, &dda);
		set_dir_texture(&dda);
		set_buf(info_ptr, &dda, x);
	}
	draw(cub);
	change_dir(cub);
	return (0);
}
