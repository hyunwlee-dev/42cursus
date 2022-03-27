/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_same(char *a, char *b)
{
	if (ft_strlen(a) == ft_strlen(b))
	{
		if (ft_strcmp(a, b) == 0)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}

void	delete_free(t_env *tmp)
{
	tmp->prev->next = tmp->next;
	if (tmp->next != 0)
		tmp->next->prev = tmp->prev;
	free_buffer(&tmp->key);
	free_buffer(&tmp->value);
	free(tmp);
}

void	delete_env(t_env *env_list, char *argv)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = env_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (is_same(tmp->key, argv))
			delete_free(tmp);
		tmp = tmp2;
	}
}

void	ft_unset(t_cmd *c_list, t_sh_data *g_data)
{
	int		size;
	t_list	*tmp;

	set_pipe(c_list);
	set_rd(c_list->r_list);
	tmp = c_list->cmd;
	size = ft_lstsize(tmp);
	if (size == 0)
		printf("unset: not enough arguments\n");
	else
	{
		while (tmp)
		{
			delete_env(g_data->env_list, tmp->content);
			tmp = tmp->next;
		}
	}
	g_data->status = 0;
}
