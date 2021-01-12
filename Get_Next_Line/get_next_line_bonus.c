/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:15 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/01/12 22:43:59 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    init_buf_safe(char **buf_safe)
{
    if (!(*buf_safe))
    {
        *buf_safe = ft_strdup("");
    }
}

int     alloc_line(char **line, char *buf_safe, ssize_t idx)
{
    if (!(*line = (char *)malloc(sizeof(char) * (idx + 1))))
        return (1);
    *(*line + idx) = '\0';
    ft_strlcpy(*line, buf_safe, idx + 1);
    return (0);
}

int     is_end(char **line, char **buf_safe)
{
    if (!(ft_strlen(*buf_safe) - ft_strlen(*line)))
    {
        free(*buf_safe);
        *buf_safe = 0;
        return (1);
    }
    return (0);
}

int     handle_buf_line(char **line, char **buf_safe, ssize_t idx)
{
    size_t line_len;
    size_t buf_s_len;

    if (alloc_line(line, *buf_safe, idx))
        return (-1);
    if (is_end(line, buf_safe))
        return (0);
    line_len = ft_strlen(*line);
    buf_s_len = ft_strlen(*buf_safe);
    if (!(*buf_safe = ft_substr(buf_safe, line_len + 1, buf_s_len - line_len)))
        return (-1);
    return (1);
}

int        get_next_line(int fd, char **line)
{
    char        buf[BUFFER_SIZE + 1];
    static char *buf_safe[OPEN_MAX];
    ssize_t     idx;
    ssize_t     read_byte;

    init_buf_safe(&(buf_safe[fd]));
    while ((read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_byte] = '\0';
        if (!(buf_safe[fd] = ft_strjoin(&(buf_safe[fd]), buf)))
            return (-1);
        idx = 0;
        while (*(buf_safe[fd] + idx) && *(buf_safe[fd] + idx) != '\n')
            idx++;
        if (*(buf_safe[fd] + idx) == '\n')
            return (handle_buf_line(line, &(buf_safe[fd]), idx));
    }
    if (!(read_byte))
    {
        idx = 0;
        while (*(buf_safe[fd] + idx) && *(buf_safe[fd] + idx) != '\n')
            idx++;
        return (handle_buf_line(line, &(buf_safe[fd]), idx));
    }
    return (-1);
}
