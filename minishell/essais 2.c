/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essais.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:05:20 by ybrutout          #+#    #+#             */
/*   Updated: 2021/10/28 15:46:28 by ybrutout         ###   ########.fr       */
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
			free_env(env_cpy, i + 1);
		if (ft_strcpy(str_cpy, env[i]) == -1)
		{
			write(1, "problème de -1\n", 15);
			return (NULL);
		}
		env_cpy[i] = str_cpy;
		str_cpy = NULL;
	}
	printf("%d\n", size_env);
	return (env_cpy);
}

int main(int argc, char **argv, char **env)
{
	char **cpy;
	int	i;

	if (argc == 0)
		printf("%s\n", argv[0]);
	cpy = cpy_env(env);
	if (!cpy)
		return (1);
	i = 0;
	while (cpy[i])
	{
		printf("%s", cpy[i]);
		i++;
	}
	printf("i == %d\n", i);
	return (0);
}
