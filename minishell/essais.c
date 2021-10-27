/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:05:20 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/27 17:12:57 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cpy_env(char **env)
{
	int		size_env;
	int		size_str;
	int		i;
	char	**env_cpy;
	char	*str_cpy;

	size_env = tab_str_len(env);
	i = -1;
	env_cpy = malloc(sizeof(char * ) * (size_env + 1));
	if (!env_cpy)
		return (ERROR);
	env_cpy[size_env] = NULL;
	while (++i < size_env)
	{
		size_str = ft_str_len(env[i]);
		str_cpy = malloc(sizeof(char) * (size_str + 1));
		if (!str_cpy)
			

	}
	return (env_cpy);
}

int main(int argc, char **argv, char **env)
{
	char 	**env;


	return (0);
}
