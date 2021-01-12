/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:18 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/01/12 20:11:00 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
char    *ft_substr(char **s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);
char    *ft_strjoin(char **s1, char const *s2);

int		get_next_line(int fd, char **line);
int     alloc_line(char **line, char *buf_safe, ssize_t idx);
int     is_end(char **line, char **buf_safe);
// int     substr_buf_safe(char **line, char **buf_safe);
int     handle_buf_line(char **line, char **buf_safe, ssize_t idx);

# endif
