/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:34:04 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/10 16:51:36 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"
# define CHILD 0

typedef struct	s_cmd
{
	char	*cmd[5];
	char	**argv;
	char	**envp;
}				t_cmd;

typedef struct	s_args
{
	char	*input_file;
	char	*output_file;
	char	*cmd1_text;
	char	*cmd2_text;
}				t_args;

typedef struct	s_total
{
	t_args	args;
	pid_t	pid;
	int		status;
	int		pipefd[2];
	t_cmd	cmd1;
	t_cmd	cmd2;
}				t_total;

int				redirect_in(char *file);
int				redirect_out(char *file);
int				connect_pipe(int pipefd[2], int io);
void			parse_args_identifier(char **argv, t_total *total);
int				check_validation_args(int argc, char **argv, t_total *total);
void			init_cmd_id(char *cmd, t_cmd *cmd_id);
int				run_execve(char *cmd, t_cmd *cmd_id);

#endif
