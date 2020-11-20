/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:38:01 by ybrutout          #+#    #+#             */
/*   Updated: 2020/11/19 16:18:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>

int				ft_atoi(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_bzero(char *s, size_t n);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

size_t			ft_strlen(const char *s);
size_t          ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif