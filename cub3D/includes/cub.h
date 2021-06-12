/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:53:34 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:17:23 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "parse.h"
# include "raycast.h"

typedef struct	s_cub
{
	t_map	map;
	t_img	img;
	t_info	info;
}				t_cub;

void			draw_background(t_cub *cub);
void			init_cub(t_cub *cub);
void			init_worldmap(t_cub *cub);
void			init_buf(t_cub *cub);
void			init_texture(t_cub *cub);
void			init_cub_texture(t_cub *cub);
int				raycaster(t_cub *cub);
void			free_arrays_integer(int **arr, int size);
int				**allocate_worldmap(t_cub cub);
int				**allocate_buf(void);
int				**allocate_texture(void);
void			load_image(t_cub *cub, int *texture, char *filename);
void			load_texture(t_cub *cub);
int				cal_rgb_to_hex(int rgb[]);
void			init_dda_struct(t_info *info_ptr, t_dda *dda, int x);
void			init_dda_sidedist(t_info *info_ptr, t_dda *dda);
void			find_hit_dda(t_info *info_ptr, t_dda *dda);
void			get_draw_point(t_info *info_ptr, t_dda *dda);
void			set_dir_texture(t_dda *dda);
void			init_texture_struct(t_info *info_ptr, t_dda *dda);
void			set_buf(t_info *info_ptr, t_dda *dda, int x);
void			load_north(t_cub *cub);
void			load_south(t_cub *cub);
void			load_west(t_cub *cub);
void			load_east(t_cub *cub);
int				click_exit(void);
void			draw(t_cub *cub);
int				key_press(int keycode, t_cub *cub);
int				key_release(int keycode, t_cub *cub);
void			key_press_no_so(t_info *info, t_dir *dir);
void			key_press_we_ea(t_info *info, t_dir *dir);
void			key_press_left_right(t_info *info, t_dir *dir);
int				change_dir(t_cub *cub);

#endif
