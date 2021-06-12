/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:38:29 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:09:37 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"
#include "libft.h"

void	init_cub_texture(t_cub *cub)
{
	t_img	*img_ptr;
	t_info	*info_ptr;

	img_ptr = &(cub->img);
	info_ptr = &(cub->info);
	if (!(info_ptr->worldmap = allocate_worldmap(*cub)))
		exit(1);
	if (!(info_ptr->buf = allocate_buf()) || \
			!(info_ptr->texture = allocate_texture()))
		exit(1);
	init_worldmap(cub);
	init_buf(cub);
	init_texture(cub);
}

void	init_cub(t_cub *cub)
{
	t_img	*img_ptr;
	t_info	*info_ptr;

	img_ptr = &(cub->img);
	info_ptr = &(cub->info);
	img_ptr->img = mlx_new_image(info_ptr->mlx, WIDTH, HEIGHT);
	info_ptr->win = mlx_new_window(info_ptr->mlx, WIDTH, \
			HEIGHT, "hyunwlee cub_3d");
	img_ptr->addr = (int *)mlx_get_data_addr(img_ptr->img, \
			&(img_ptr->bits_per_pixel), &(img_ptr->line_length), \
			&(img_ptr->endian));
	info_ptr->pos_x = cub->map.player_x + 0.5;
	info_ptr->pos_y = cub->map.player_y + 0.5;
	info_ptr->dir_x = -1;
	info_ptr->dir_y = 0;
	info_ptr->plane_x = 0;
	info_ptr->plane_y = 0.66;
	info_ptr->movespeed = 0.05;
	info_ptr->rotatespeed = 0.03;
	info_ptr->key_w = 0;
	info_ptr->key_a = 0;
	info_ptr->key_s = 0;
	info_ptr->key_d = 0;
	info_ptr->key_left = 0;
	info_ptr->key_right = 0;
}
