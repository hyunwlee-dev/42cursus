/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:12:18 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/04/06 19:37:09 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

size_t	gnl_strlen(const char *s);
char	*gnl_substr(char **s, unsigned int start, size_t len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strdup(const char *str);
char	*gnl_strjoin(char **s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
