/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:00 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/10 16:52:37 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		check_validation_args(int argc, char **argv, t_total *total)
{
	int	fd;

	if (argc != 5)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		return (-1);
	}
	close(fd);
	parse_args_identifier(argv, total);
	return (0);
}

void	parse_args_identifier(char **argv, t_total *total)
{
	(&(total->args))->input_file = argv[1];
	(&(total->args))->cmd1_text = argv[2];
	(&(total->args))->cmd2_text = argv[3];
	(&(total->args))->output_file = argv[4];
}
