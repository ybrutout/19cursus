/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:10:12 by ybrutout          #+#    #+#             */
/*   Updated: 2022/05/04 11:50:28 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN		0
#define STDOUT		1
#define STDERR		2
#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5

typedef struct	s_base
{
	char			**av;
	int				size;
	int				type;
	int				fd[2];
	struct s_base	*next;
	struct s_base	*prev;
}				t_base;

/*
**====================================
**============Part utils==============
**====================================
*/

int		ft_strlen(char *str)
{
	int	i =	0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*str)
{
	int		size = ft_strlen(str);
	char	*new;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

/*
**====================================
**============Part error==============
**====================================
*/

void	exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void	exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int		exit_cd_1(void)
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n")); 
	return (EXIT_FAILURE);
}

int		exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}

/*
**====================================
**============Part parsing============
**====================================
*/

void	ft_lstadd_back(t_base **ptr, t_base *new)
{
	t_base	*tmp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		tmp = *ptr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int		arg_size(char **av)
{
	int	i = 0;
	while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	return (i);
}

int		check_end(char *av)
{
	if (!av)
		return (TYPE_END);
	if (strcmp(av, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(av, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

int		arg_parser(t_base **ptr, char **av)
{
	int		size = arg_size(av);
	t_base	*new;

	if (!(new = (t_base *)malloc(sizeof(t_base))))
		exit_fatal();
	if (!(new->av = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	new->av[size] = NULL;
	while (--size >= 0)
		new->av[size] = ft_strdup(av[size]);
	new->type = check_end(av[new->size]);
	ft_lstadd_back(ptr, new);
	return (new->size);
}

/*
**====================================
**============Part execve=============
**====================================
*/

void	exec_cmd(t_base *tmp, char **env)
{
	pid_t	pid;
	int		status;
	int		pipe_open;

	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)	//child
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->fd[STDOUT], STDOUT) < 0 )
			exit_fatal();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->prev->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(tmp->av[0], tmp->av, env)) < 0)
			exit_execve(tmp->av[0]);
		exit(EXIT_SUCCESS);
	}
	else	//parent
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(tmp->fd[STDOUT]);
			if (!tmp->next || tmp->type == TYPE_BREAK)
				close(tmp->fd[STDIN]);
		}
		if (tmp->prev && tmp->prev->type == TYPE_PIPE)
			close(tmp->prev->fd[STDIN]);
	}
}

void	exec_cmds(t_base *ptr, char **env)
{
	t_base	*tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp("cd", tmp->av[0]) == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir(tmp->av[1]))
				exit_cd_2(tmp->av[1]);
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

/*
**====================================
**============Part main===============
**====================================
*/

void	free_all(t_base *ptr)
{
	t_base	*tmp;
	int		i;

	while (ptr)
	{
		tmp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->av[i++]);
		free(ptr->av);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_base	*ptr = NULL;
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += arg_parser(&ptr, &av[i]);
			if (!av[i])
				break;
			else
				i++;
		}
		if (ptr)
			exec_cmds(ptr, env);
		free_all(ptr);
	}
	return (0);
}

