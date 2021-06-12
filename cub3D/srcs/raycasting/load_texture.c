/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:38:34 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/02 20:46:26 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"
#include "libft.h"

void	load_north(t_cub *cub)
{
	char	*north[4];
	int		i;
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	north[0] = ft_strdup("./textures/");
	north[1] = ft_substr(cub->map.no, 2, ft_strlen(cub->map.no) - 2);
	north[2] = ft_strjoin(north[0], north[1]);
	north[3] = ft_strjoin(north[2], ".xpm");
	load_image(cub, (info_ptr->texture[0]), north[3]);
	i = -1;
	while (++i < 4)
		free(north[i]);
}

void	load_south(t_cub *cub)
{
	char	*south[4];
	int		i;
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	south[0] = ft_strdup("./textures/");
	south[1] = ft_substr(cub->map.so, 2, ft_strlen(cub->map.so) - 2);
	south[2] = ft_strjoin(south[0], south[1]);
	south[3] = ft_strjoin(south[2], ".xpm");
	load_image(cub, (info_ptr->texture[1]), south[3]);
	i = -1;
	while (++i < 4)
		free(south[i]);
}

void	load_west(t_cub *cub)
{
	char	*west[4];
	int		i;
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	west[0] = ft_strdup("./textures/");
	west[1] = ft_substr(cub->map.we, 2, ft_strlen(cub->map.we) - 2);
	west[2] = ft_strjoin(west[0], west[1]);
	west[3] = ft_strjoin(west[2], ".xpm");
	load_image(cub, (info_ptr->texture[2]), west[3]);
	i = -1;
	while (++i < 4)
		free(west[i]);
}

void	load_east(t_cub *cub)
{
	char	*east[4];
	int		i;
	t_info	*info_ptr;

	info_ptr = &(cub->info);
	east[0] = ft_strdup("./textures/");
	east[1] = ft_substr(cub->map.ea, 2, ft_strlen(cub->map.ea) - 2);
	east[2] = ft_strjoin(east[0], east[1]);
	east[3] = ft_strjoin(east[2], ".xpm");
	load_image(cub, (info_ptr->texture[3]), east[3]);
	i = -1;
	while (++i < 4)
		free(east[i]);
}

void	load_texture(t_cub *cub)
{
	load_north(cub);
	load_south(cub);
	load_west(cub);
	load_east(cub);
}
