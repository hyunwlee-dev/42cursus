/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 02:24:58 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 13:23:28 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parse.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;

	if (argc != 2)
		return (0);
	init_identities(&cub.map);
	if (parse_main(argv[1], &cub.map))
	{
		printf("[MAP VALIDATION FAIL!!]\n");
		free_array(&cub.map);
		return (1);
	}
	printf("[MAP VALIDATION SUCCESS]\n");
	cub.info.mlx = mlx_init();
	init_cub_texture(&cub);
	load_texture(&cub);
	init_cub(&cub);
	mlx_hook(cub.info.win, KEYPRESS, KEYPRESSMASK, key_press, &cub);
	mlx_hook(cub.info.win, KEYRELEASE, KEYRELEASEMASK, key_release, &cub);
	mlx_hook(cub.info.win, 17, 1L << 17, click_exit, &cub);
	mlx_loop_hook(cub.info.mlx, raycaster, &cub);
	mlx_loop(cub.info.mlx);
	return (0);
}
