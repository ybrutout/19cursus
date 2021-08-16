/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:36:48 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/16 11:10:53 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_general
{
	unsigned int	nb;
	int				pid_server;
	int				const_bit;
	char			*str;
	int				i;
	int				strlen;
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

//bonus
t_gen			*the_struct(int pid_server, int strlen, char *arg, int button);
int				stage_bonus(int *strlen, int *stage, int i, int pid_client);
void			end_or_error(t_gen *general);

# define MALLOC_ERROR 1
# define PID_ERROR 2
# define ARG_ERROR 3
# define END 4
# define INIT 10
# define CHANGE 11
# define RECEVE 12

#endif
