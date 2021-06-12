/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:32:28 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/10 16:53:55 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd_id(char *cmd, t_cmd *cmd_id)
{
	char	**cmd_partitions;

	cmd_partitions = ft_split(cmd, ' ');
	cmd_id->cmd[0] = ft_strjoin("/usr/local/bin/", cmd_partitions[0]);
	cmd_id->cmd[1] = ft_strjoin("/usr/bin/", cmd_partitions[0]);
	cmd_id->cmd[2] = ft_strjoin("/bin/", cmd_partitions[0]);
	cmd_id->cmd[3] = ft_strjoin("/usr/sbin/", cmd_partitions[0]);
	cmd_id->cmd[4] = ft_strjoin("/sbin/", cmd_partitions[0]);
	cmd_id->argv = cmd_partitions;
}

int		run_execve(char *cmd, t_cmd *cmd_id)
{
	int	i;

	i = 0;
	init_cmd_id(cmd, cmd_id);
	while (i < 5)
		execve(cmd_id->cmd[i++], cmd_id->argv, cmd_id->envp);
	perror(cmd_id->argv[0]);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_total	total;

	if (check_validation_args(argc, argv, &total))
		return (0);
	pipe(total.pipefd);
	total.pid = fork();
	if (total.pid == CHILD)
	{
		if (redirect_in(total.args.input_file) || \
			connect_pipe(total.pipefd, STDOUT_FILENO) || \
			run_execve(total.args.cmd1_text, &total.cmd1))
			exit(1);
	}
	else if (total.pid > 0)
	{
		waitpid(total.pid, &total.status, 0);
		if (WIFEXITED(total.status) == 0)
			exit(1);
		if (redirect_out(total.args.output_file) || \
			connect_pipe(total.pipefd, STDIN_FILENO) || \
			run_execve(total.args.cmd2_text, &total.cmd2))
			exit(1);
	}
	return (0);
}
