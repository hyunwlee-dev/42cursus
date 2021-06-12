/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:40:04 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:15:25 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

int		key_press(int keycode, t_cub *cub)
{
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		info_ptr->key_w = 1;
	else if (keycode == KEY_A)
		info_ptr->key_a = 1;
	else if (keycode == KEY_S)
		info_ptr->key_s = 1;
	else if (keycode == KEY_D)
		info_ptr->key_d = 1;
	else if (keycode == KEY_LEFT)
		info_ptr->key_left = 1;
	else if (keycode == KEY_RIGHT)
		info_ptr->key_right = 1;
	return (0);
}

int		key_release(int keycode, t_cub *cub)
{
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		info_ptr->key_w = 0;
	else if (keycode == KEY_A)
		info_ptr->key_a = 0;
	else if (keycode == KEY_S)
		info_ptr->key_s = 0;
	else if (keycode == KEY_D)
		info_ptr->key_d = 0;
	else if (keycode == KEY_LEFT)
		info_ptr->key_left = 0;
	else if (keycode == KEY_RIGHT)
		info_ptr->key_right = 0;
	return (0);
}

int		change_dir(t_cub *cub)
{
	t_dir	dir;
	t_img	*img_ptr;
	t_info	*info_ptr;

	img_ptr = &(cub->img);
	info_ptr = &(cub->info);
	mlx_destroy_image(info_ptr->mlx, img_ptr->img);
	img_ptr->img = mlx_new_image(info_ptr->mlx, WIDTH, HEIGHT);
	img_ptr->addr = (int *)mlx_get_data_addr(img_ptr->img, \
			&(img_ptr->bits_per_pixel), \
			&(img_ptr->line_length), &(img_ptr->endian));
	if (info_ptr->key_w || info_ptr->key_s)
		key_press_no_so(info_ptr, &dir);
	if (info_ptr->key_a || info_ptr->key_d)
		key_press_we_ea(info_ptr, &dir);
	if (info_ptr->key_left || info_ptr->key_right)
		key_press_left_right(info_ptr, &dir);
	return (1);
}
