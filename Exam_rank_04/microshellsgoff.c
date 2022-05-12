#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
typedef struct  s_cmd
{
    char            **args;
    int             pipe;
    int             fd[2];
    struct s_cmd    *next;
}               t_cmd;
// void debug(t_cmd * cmds)
// {
//  t_cmd * tmp = cmds;
//  int i;
//  while (tmp)
//  {
//      i = 0;
//      while (tmp->args[i])
//      {
//          printf("%s ", tmp->args[i++]);
//      }
//      printf("\n");
//      tmp = tmp->next;
//  }
// }

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void print_err(char *str)
{
    write(2, str, ft_strlen(str));
}

void ft_quit()
{
    print_err("error: fatal\n");
    exit(1);
}

t_cmd *new_node(char **av, int *n)
{
    int i = 0;
    // malloc node
    t_cmd *ret = malloc(sizeof(t_cmd));
    if (!ret)
        ft_quit();
    // malloc args
    if (!(ret->args = malloc(sizeof(char *) * 200)))  //yolo
        ft_quit();
    // remember to set everything to 0
    ret->pipe = 0;
    ret->next = 0;
    ret->fd[0] = 0;
    ret->fd[1] = 0;
    // copy strings in args until we find ";" or "|" or av ends
    while (av[*n] && strcmp(av[*n], ";") && strcmp(av[*n], "|"))
        // remember n is a pointer
        ret->args[i++] = av[(*n)++];
    // remember to null-terminate args
    ret->args[i] = 0;
    // set pipe to 1 if we encountered a "|" at the end
    if (av[*n] && !strcmp(av[*n], "|"))
        ret->pipe = 1;
    return (ret);
}

int cd(char **argv)
{
    // only works with 1 argument
    if (argv[1] == 0 || argv[2] != 0)
    {
        print_err("error: cd: bad arguments\n");
        return(1);
    }
    // check if chdir fails
    if (chdir(argv[1]))
    {
        print_err("error: cd: cannot change directory to ");
        print_err(argv[1]);
        print_err("\n");
        return(1);
    }
    return(0);
}

int exec(t_cmd *cmd, char **env)
{
    int id;
    // builtin cd (no fork!)
    if (!strcmp(cmd->args[0], "cd"))
        return(cd(cmd->args));
    // check if fork fails
    if ((id = fork()) == -1)
        ft_quit();
    // child process
    if (!id)
    {
        // if there is a pipe in or out, we dup2
        if (cmd->fd[1])
            dup2(cmd->fd[1], 1);
        if (cmd->fd[0])
            dup2(cmd->fd[0], 0);
        execve(cmd->args[0], cmd->args, env);
        // if execve returns it means it failed
        print_err("error: cannot execute ");
        print_err(cmd->args[0]);
        print_err("\n");
        exit(1);
    }
    // parent process
    waitpid(id, 0, 0);
    // remeber to close open fds
    if (cmd->fd[1])
        close(cmd->fd[1]);
    if (cmd->fd[0])
        close(cmd->fd[0]);
    return(0);
}

void do_stuff(t_cmd * cmds, char **env)
{
    t_cmd * tmp = cmds;
    int pp[2];
    while (tmp)
    {
        // pipe management
        if (tmp->pipe)
        {
            if (pipe(pp) == -1)
                // check if pipe fails
                ft_quit();
            // pp[0] = read ; pp[1] = write
            tmp->fd[1] = pp[1];
            tmp->next->fd[0] = pp[0];
        }
        exec(tmp, env);
        tmp = tmp->next;
    }
}

void free_stuff(t_cmd *cmds)
{
    t_cmd * tmp;
    while (cmds)
    {
        tmp = cmds->next;
        free(cmds->args);
        free(cmds);
        cmds = tmp;
    }
}

int main(int ac, char **av, char **env)
{
    int n = 0;
    t_cmd *list = 0;
    t_cmd *tmp;
    // skip av[0]
    while (++n < ac)
    {
        // skip multiple ";"
        if (!strcmp(av[n], ";"))
            continue;
        // the first node
        if (!list)
        {
            // we need to pass n as a pointer (to increment it)
            list = new_node(av, &n);
            tmp = list;
        }
        // every other node
        else
        {
            // we need to pass n as a pointer (to increment it)
            tmp->next = new_node(av, &n);
            tmp = tmp->next;
        }
    }
    // debug(list);
    do_stuff(list, env);
    free_stuff(list);
}
