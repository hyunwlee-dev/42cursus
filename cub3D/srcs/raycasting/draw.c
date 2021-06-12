/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:47:38 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/02 21:38:38 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

void	load_image(t_cub *cub, int *texture, char *filename)
{
	t_img	*img_ptr;
	t_info	*info_ptr;
	int		x;
	int		y;

	img_ptr = &(cub->img);
	info_ptr = &(cub->info);
	img_ptr->img = mlx_xpm_file_to_image(info_ptr->mlx, filename, \
			&img_ptr->img_w, &img_ptr->img_h);
	img_ptr->addr = (int *)mlx_get_data_addr(img_ptr->img, \
			&(img_ptr->bits_per_pixel), &(img_ptr->line_length), \
			&(img_ptr->endian));
	y = -1;
	while (++y < img_ptr->img_h)
	{
		x = -1;
		while (++x < img_ptr->img_w)
			texture[y * img_ptr->img_w + x] = \
				img_ptr->addr[y * img_ptr->img_w + x];
	}
	mlx_destroy_image(info_ptr->mlx, img_ptr->img);
}

int		cal_rgb_to_hex(int rgb[])
{
	int	color;

	color = rgb[0] << 16;
	color += rgb[1] << 8;
	color += rgb[2];
	return (color);
}

void	draw_background(t_cub *cub)
{
	t_info	*info_ptr;
	t_img	*img_ptr;
	int		count_h;
	int		count_w;

	info_ptr = &(cub->info);
	img_ptr = &(cub->img);
	count_h = -1;
	while (++count_h < HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIDTH)
		{
			if (count_h < HEIGHT / 2)
				info_ptr->buf[count_h][count_w] = cal_rgb_to_hex(cub->map.c);
			else
				info_ptr->buf[count_h][count_w] = cal_rgb_to_hex(cub->map.f);
		}
	}
	mlx_put_image_to_window((&(cub->info))->mlx, \
			(&(cub->info))->win, (&(cub->img))->img, 0, 0);
}

void	draw(t_cub *cub)
{
	t_info	*info_ptr;
	t_img	*img_ptr;
	int		x;
	int		y;

	info_ptr = &(cub->info);
	img_ptr = &(cub->img);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			img_ptr->addr[y * WIDTH + x] = info_ptr->buf[y][x];
	}
	mlx_put_image_to_window((&(cub->info))->mlx, \
			(&(cub->info))->win, (&(cub->img))->img, 0, 0);
}
