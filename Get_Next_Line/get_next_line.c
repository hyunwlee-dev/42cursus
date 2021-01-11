/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:15 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/01/11 17:18:31 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int        get_next_line(int fd, char **line)
{
    char        buf[BUFFER_SIZE + 1];
    static char *buf_safe;
    char        *tmp;
    ssize_t      idx;
    ssize_t      read_byte;

    if (!buf_safe)
        buf_safe = ft_strdup("");
    while ((read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        idx = 0;
        buf[read_byte] = '\0';
        tmp = ft_strjoin(buf_safe, buf);
        if (!tmp)
            return (-1);
        free(buf_safe);
        buf_safe = tmp;
        while (*(buf_safe + idx) && *(buf_safe + idx) != '\n')
            idx++;
        if (*(buf_safe + idx) == '\n')
        {
            *line = (char *)malloc(sizeof(char) * (idx + 1));
            if (!(*line))
                return (-1);
            (*line)[idx] = '\0';
            ft_strlcpy(*line, buf_safe, idx + 1);
            if (!(ft_strlen(buf_safe) - ft_strlen(*line)))
            {
                free(buf_safe);
                buf_safe = 0;
                return (0);
            }
            tmp = ft_substr(buf_safe, ft_strlen(*line) + 1, ft_strlen(buf_safe) - ft_strlen(*line));
            free(buf_safe);
            buf_safe = tmp;
            return (1);
        }
    }
    if (read_byte == 0)
    {
        idx = 0;
        while (*(buf_safe + idx) && *(buf_safe + idx) != '\n')
            idx++;
        if (!(*line = (char *)malloc(sizeof(char) * (idx + 1))))
            return (-1);
        *(*line + idx) = '\0';
        ft_strlcpy(*line, buf_safe, idx + 1);
        if (!(ft_strlen(buf_safe) - ft_strlen(*line)))
        {
            free(buf_safe);
            buf_safe = 0;
            return (0);
        }
        buf_safe = ft_substr(buf_safe, ft_strlen(*line) + 1, ft_strlen(buf_safe) - ft_strlen(*line));
        return (1);
    }
    // if (read_byte == -1)
        return (-1);
}
// int main()
// {
//     int fd = open("input.txt", O_RDWR);
//     if (fd == -1)
//         return (0);
//     int        num = 1;
//     char        *line;
//     while (num == 1)
//     {
//         num = get_next_line(fd, &line);
//         printf("%s\n", line);
//         free(line);
//         line = 0;
//     }
//     close(fd);
//     return (0);
// }
