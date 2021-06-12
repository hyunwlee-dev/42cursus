/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:14:40 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:20:41 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_texture_direction(char **str, t_map **map)
{
	if (!ft_strncmp(str[0], "NO", 3))
	{
		free((*map)->no);
		(*map)->no = ft_strdup(*(str + 1));
		(*map)->check.no = 1;
	}
	else if (!ft_strncmp(str[0], "SO", 3))
	{
		free((*map)->so);
		(*map)->so = ft_strdup(*(str + 1));
		(*map)->check.so = 1;
	}
	else if (!ft_strncmp(str[0], "WE", 3))
	{
		free((*map)->we);
		(*map)->we = ft_strdup(*(str + 1));
		(*map)->check.we = 1;
	}
	else if (!ft_strncmp(str[0], "EA", 3))
	{
		free((*map)->ea);
		(*map)->ea = ft_strdup(*(str + 1));
		(*map)->check.ea = 1;
	}
}

int		check_texture(char **str, int cnt, t_map **map)
{
	if (cnt != 2)
		return (0);
	check_texture_direction(str, map);
	return (1);
}
