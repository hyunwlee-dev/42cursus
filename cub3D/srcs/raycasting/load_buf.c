/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:56:42 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:20:41 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

void	set_dir_texture(t_dda *dda)
{
	if (dda->side == 0 && dda->raydir_x > 0)
		(&(dda->texture))->texnum = 0;
	else if (dda->side == 0 && dda->raydir_x < 0)
		(&(dda->texture))->texnum = 1;
	else if (dda->side == 1 && dda->raydir_y > 0)
		(&(dda->texture))->texnum = 2;
	else if (dda->side == 1 && dda->raydir_y < 0)
		(&(dda->texture))->texnum = 3;
}

void	init_texture_struct(t_info *info_ptr, t_dda *dda)
{
	(&(dda->texture))->texnum = info_ptr->worldmap[dda->map_x][dda->map_y] - 1;
	if (dda->side == 0)
		(&(dda->texture))->wall_x = \
			info_ptr->pos_y + dda->perpwalldist * dda->raydir_y;
	else
		(&(dda->texture))->wall_x = \
			info_ptr->pos_x + dda->perpwalldist * dda->raydir_x;
	(&(dda->texture))->wall_x -= floor((&(dda->texture))->wall_x);
	(&(dda->texture))->tex_x = \
			(int)((&(dda->texture))->wall_x * (double)TEXWIDTH);
}

void	set_buf(t_info *info_ptr, t_dda *dda, int x)
{
	int			y;
	t_texture	*tex_ptr;

	tex_ptr = &(dda->texture);
	if (dda->side == 0 && dda->raydir_x > 0)
		tex_ptr->tex_x = TEXWIDTH - tex_ptr->tex_x - 1;
	if (dda->side == 1 && dda->raydir_y < 0)
		tex_ptr->tex_x = TEXWIDTH - tex_ptr->tex_x - 1;
	tex_ptr->step = 1.0 * TEXHEIGHT / dda->lineheight;
	tex_ptr->texpos = (dda->drawstart - HEIGHT / 2 + dda->lineheight / 2) \
		* tex_ptr->step;
	y = dda->drawstart - 1;
	while (++y < dda->drawend)
	{
		tex_ptr->tex_y = \
			(int)tex_ptr->texpos & (TEXHEIGHT - 1);
		tex_ptr->texpos += tex_ptr->step;
		tex_ptr->color = \
			info_ptr->texture[tex_ptr->texnum][TEXHEIGHT \
			* tex_ptr->tex_y + tex_ptr->tex_x];
		info_ptr->buf[y][x] = tex_ptr->color;
	}
}
