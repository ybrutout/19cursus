/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:57:19 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/28 15:33:47 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ERROR 0

//LIBFT
int		tab_str_len(char **tabstr);
int		ft_str_len(char *str);
int		ft_strcpy(char *dst, char *src);

//ERROR
void	free_env(char ** env, int nb);

#endif
