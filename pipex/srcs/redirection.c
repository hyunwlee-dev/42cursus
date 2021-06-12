/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:57:45 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/10 16:55:20 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (1);
	close(fd);
	return (0);
}

int	redirect_out(char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		return (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (1);
	close(fd);
	return (0);
}

int	connect_pipe(int pipefd[2], int io)
{
	if (dup2(pipefd[io], io) == -1)
		return (1);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
