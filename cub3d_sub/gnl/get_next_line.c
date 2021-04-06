/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:15 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/03/27 18:13:19 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		init_buf_safe(char **line, char **buf_safe, int fd, ssize_t *idx)
{
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (1);
	*line = 0;
	if (!(*buf_safe))
		*buf_safe = gnl_strdup("");
	*idx = 0;
	return (0);
}

int		alloc_line(char **line, char *buf_safe, ssize_t idx)
{
	if (!(*line = (char *)malloc(sizeof(char) * (idx + 1))))
		return (1);
	*(*line + idx) = '\0';
	gnl_strlcpy(*line, buf_safe, idx + 1);
	return (0);
}

int		is_end(char **line, char **buf_safe)
{
	if (!(gnl_strlen(*buf_safe) - gnl_strlen(*line)))
	{
		free(*buf_safe);
		*buf_safe = 0;
		return (1);
	}
	return (0);
}

int		handle_buf_line(char **line, char **buf_safe, ssize_t idx)
{
	size_t line_len;
	size_t buf_s_len;

	if (alloc_line(line, *buf_safe, idx))
		return (-1);
	if (is_end(line, buf_safe))
		return (0);
	line_len = gnl_strlen(*line);
	buf_s_len = gnl_strlen(*buf_safe);
	if (!(*buf_safe = gnl_substr(buf_safe, line_len + 1, buf_s_len - line_len)))
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*buf_safe;
	ssize_t		idx;
	ssize_t		read_byte;

	if (init_buf_safe(line, &buf_safe, fd, &idx))
		return (-1);
	while ((read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_byte] = '\0';
		if (!(buf_safe = gnl_strjoin(&buf_safe, buf)))
			return (-1);
		while (*(buf_safe + idx) && *(buf_safe + idx) != '\n')
			idx++;
		if (*(buf_safe + idx) == '\n')
			return (handle_buf_line(line, &buf_safe, idx));
	}
	if (!(read_byte))
	{
		idx = 0;
		while (*(buf_safe + idx) && *(buf_safe + idx) != '\n')
			idx++;
		return (handle_buf_line(line, &buf_safe, idx));
	}
	return (-1);
}
