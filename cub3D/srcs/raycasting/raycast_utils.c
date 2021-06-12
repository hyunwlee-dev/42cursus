/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:24:01 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:10:12 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "raycast.h"

void	free_arrays_integer(int **arr, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
		free(arr[idx++]);
	free(arr);
}

int		**allocate_texture(void)
{
	int	**result;
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	if (!(result = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	while (idx < 4)
	{
		if (!(result[idx] = (int *)malloc(sizeof(int) \
						* (TEXHEIGHT * TEXWIDTH))))
		{
			free_arrays_integer(result, idx);
			return (NULL);
		}
		idx++;
	}
	return (result);
}

int		**allocate_buf(void)
{
	int	**result;
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	if (!(result = (int **)malloc(sizeof(int *) * (HEIGHT))))
		return (NULL);
	while (idx < HEIGHT)
	{
		if (!(result[idx] = (int *)malloc(sizeof(int) * (WIDTH))))
		{
			free_arrays_integer(result, idx);
			return (NULL);
		}
		idx++;
	}
	return (result);
}

int		**allocate_worldmap(t_cub cub)
{
	int	**result;
	int	idx;
	int	jdx;

	idx = 0;
	jdx = 0;
	if (!(result = (int **)malloc(sizeof(int *) * (cub.map.tmp_row))))
		return (NULL);
	while (idx < cub.map.tmp_row)
	{
		if (!(result[idx] = (int *)malloc(sizeof(int) \
					* (cub.map.tmp_column))))
		{
			free_arrays_integer(result, idx);
			return (NULL);
		}
		idx++;
	}
	return (result);
}

int		click_exit(void)
{
	exit(1);
}
