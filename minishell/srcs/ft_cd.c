/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_cwd_arg(char *cwd, char *tmp)
{
	char	*ret;
	char	*tmp2;

	tmp2 = ft_strjoin(cwd, "/");
	ret = ft_strjoin(tmp2, tmp);
	free(tmp2);
	return (ret);
}

void	change_cwd_path(char *arg)
{
	char	*cwd;
	char	*path;

	cwd = getcwd(0, 5000);
	path = join_cwd_arg(cwd, arg);
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", arg);
		g_data->status = 1;
	}
	else
		g_data->status = 0;
	free(cwd);
	free(path);
}

void	change_abs_path(char *path)
{
	if (chdir(path) == -1)
	{
		printf("cd: no such file or directory: %s\n", path);
		g_data->status = 1;
	}
	else
		g_data->status = 0;
}

void	ft_cd(t_cmd *c_list)
{
	int		size;
	char	*tmp;

	set_pipe(c_list);
	set_rd(c_list->r_list);
	size = ft_lstsize(c_list->cmd);
	if (size == 1)
		chdir(get_env_value("HOME"));
	else
	{
		tmp = c_list->cmd->next->content;
		if (ft_strchr(tmp, '/') == 0)
			change_cwd_path(tmp);
		else
			change_abs_path(tmp);
	}
}
