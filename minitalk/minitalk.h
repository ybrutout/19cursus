/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:36:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/09 15:22:19 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h> //tests
# include <signal.h>
# include <stdlib.h>

//libft
int					ft_atoi(char *str);
char				*itoa_base_remix(int nb, int size);
unsigned int		ft_strlen(char *str);
int					const_value(int nb);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);

#endif
