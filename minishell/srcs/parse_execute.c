/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*make_token_list(char *command)
{
	char	*argv;
	t_list	*tmp;

	tmp = 0;
	while (*command)
	{
		argv = get_token(&command);
		if (argv != 0)
			ft_lstadd_back(&(tmp), ft_lstnew((void *)argv));
	}
	return (tmp);
}

void	parse_execute2(t_cmd *c_list)
{
	t_cmd	*tmp_list;

	tmp_list = c_list;
	while (c_list && my_strcmp(c_list->cmd->content, "") != 0)
	{
		execute(c_list);
		c_list = c_list->next;
	}
	while (tmp_list && my_strcmp(tmp_list->cmd->content, "") != 0)
	{
		waitpid(tmp_list->pid, &g_data->status, 0);
		tmp_list = tmp_list->next;
	}
}

void	parse_execute(char *command)
{
	t_cmd	*c_list;
	char	**tmp_command;
	char	**back_up;
	t_cmd	*c_backup;

	c_list = 0;
	tmp_command = ft_split2(command, '|', 0, 0);
	back_up = tmp_command;
	while (*tmp_command)
	{
		if (*(tmp_command + 1) == 0)
			cmd_lstadd_back(&c_list, make_cmd(ft_strdup(*tmp_command), 0));
		else
			cmd_lstadd_back(&c_list, make_cmd(ft_strdup(*tmp_command), 1));
		tmp_command++;
	}
	c_backup = c_list;
	free_split(back_up);
	parse_execute2(c_list);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_data->main_term);
	if (WIFEXITED(g_data->status))
		g_data->ret = WEXITSTATUS(g_data->status);
	free_cmd(c_backup);
}
