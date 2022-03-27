/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_num_str(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static	void	norm_pass(char *b)
{
	printf("exit\n");
	printf("bash: exit: %s: numeric argument required\n", b);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_data->child_term);
	exit(255);
}

static	void	norm(void)
{
	printf("exit\n");
	tcsetattr(STDIN_FILENO, TCSANOW, &g_data->child_term);
}

void	ft_exit(t_cmd *c_list, t_sh_data *g_data)
{
	int	ret;

	set_pipe(c_list);
	set_rd(c_list->r_list);
	if ((ft_lstsize(c_list->cmd)) == 1)
	{
		norm();
		exit(g_data->ret);
	}
	else if ((ft_lstsize(c_list->cmd)) == 2)
	{
		if (is_num_str(c_list->cmd->next->content))
		{
			ret = ft_atoi(c_list->cmd->next->content);
			norm();
			exit(ret);
		}
		else
			norm_pass(c_list->cmd->next->content);
	}
	else
	{
		printf("bash: exit: too many arguments\n");
		g_data->status = 1;
	}
}
