/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:24:41 by ybrutout          #+#    #+#             */
/*   Updated: 2021/01/13 16:13:37 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int					get_next_line(int fd, char **line);
int					gnl_cmp(char *str, char c);
int					gnl_if_free(char *s1, int j, char *s2);
char				*gnl_sve(char *save, char c);
char				*gnl_strdup(char *save, char c);
char				*gnl_strjoin(char *s1, char *s2);
ssize_t				gnl_return(char *save, ssize_t reader, char **line);
size_t				ft_strlen(char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif
