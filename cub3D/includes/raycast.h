/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:27:06 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:16:55 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# define WIDTH 800
# define HEIGHT 600
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# include "cub.h"
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef	struct	s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotatespeed;
	int		**worldmap;
	int		**buf;
	int		**texture;
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
}				t_info;

typedef struct	s_dir
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;
	double	new_x;
	double	new_y;
	int		sign;
}				t_dir;

typedef struct	s_texture
{
	int		texnum;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	int		color;
}				t_texture;

typedef struct	s_dda
{
	int			map_x;
	int			map_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	t_texture	texture;
}				t_dda;

#endif
