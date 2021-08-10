/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:36:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/10 17:08:08 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_general
{
	int				nb;
	int				pid_server;
	int				const_bit;
	char			*str;
}				t_gen;

//libft
int				ft_atoi(char *str);
char			*itoa_base_remix(int nb, int size);
unsigned int	ft_strlen(char *str);
int				const_value(int nb);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_error_message(int message);
int				ft_pow(int nb, int exposant);
int				init_client_server(int	nb, int	*stage, int len);
void			send_binary(unsigned int nb, int pid_server, int len);
int				stage_three(int *strlen, int *stage, int i);
char			*received_char(int strlen, int i, int *stage);
char			*init_str(int strlen, int *nb);

# define MALLOC_ERROR 1
# define PID_ERROR 2
# define ARG_ERROR 3

#endif
