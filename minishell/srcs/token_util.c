/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:17:09 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_rd(char *buf, char **command)
{
	if (**command == '>')
	{
		if (*(*command + 1) == '>')
		{
			*buf = '>';
			*(buf + 1) = '>';
			*command = *command + 2;
		}
		else
			rd_norm_pass(buf, command);
	}
	else if (**command == '<')
	{
		if (*(*command + 1) == '<')
		{
			*buf = '<';
			*(buf + 1) = '<';
			*command = *command + 2;
		}
		else
			rd_norm_pass(buf, command);
	}
	else
		rd_norm_pass(buf, command);
}

int	find_qt(char *buf, char **command, char c)
{
	int	i;

	i = 1;
	buf[0] = **command;
	*command = *command + 1;
	while (**command)
	{
		if (**command == c)
			break ;
		buf[i] = **command;
		*command = *command + 1;
		i++;
	}
	buf[i++] = **command;
	*command = *command + 1;
	return (i);
}

void	none_specific(char *buf, char **command)
{
	int	i;

	i = 0;
	while (**command)
	{
		if (**command == '"')
			i = i + find_qt(buf + i, command, '"');
		else if (**command == '\'')
			i = i + find_qt(buf + i, command, '\'');
		else
		{
			if (**command == '>' || **command == '<' || **command == '|')
				break ;
			if (**command == '\t' || **command == '\n' || **command == ' ')
			{
				*command = *command + 1;
				break ;
			}
			buf[i] = **command;
			*command = *command + 1;
			i++;
		}
	}
}

void	env(char *buf, char **command)
{
	int	i;

	i = 0;
	while (**command)
	{
		if (**command == ' ' || **command == '\t' || **command == '\n'
			|| **command == '|' || **command == '>' || **command == '<')
		{
			if (**command == ' ' || **command == '\t' || **command == '\n')
				*command = *command + 1;
			break ;
		}
		buf[i] = **command;
		*command = *command + 1;
		i++;
	}
}

char	*get_token(char **command)
{
	char	buf[9000];

	reset_buf(buf);
	while (**command == ' ' || **command == '\t')
		*command = *command + 1;
	if (**command == '"')
		find_qt(buf, command, '"');
	else if (**command == '\'')
		find_qt(buf, command, '\'');
	else if (**command == '|' || **command == '<' || **command == '>')
		pipe_rd(buf, command);
	else
		none_specific(buf, command);
	return (ft_strdup(buf));
}
