/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_off(int sig_number)
{
	(void)sig_number;
	signal(SIGINT, main_signal);
	signal(SIGQUIT, main_signal);
}

void	main_signal(int sig_number)
{
	if (sig_number == SIGINT)
	{
		rl_replace_line("", 0);
		if (g_data->forked == 0 && g_data->count == 0)
			write(1, "\n$ ", 3);
		else if (g_data->forked == 1)
			write(1, "\n", 1);
		g_data->ret = 130;
		rl_redisplay();
	}
	else if (sig_number == SIGQUIT)
	{
		if (g_data->forked == 1)
		{
			write(1, "Quit\n", 5);
			g_data->ret = 131;
		}
		else if (g_data->forked == 0 && g_data->count == 0)
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else if (sig_number == SIGCHLD)
		g_data->count = g_data->count - 1;
}
