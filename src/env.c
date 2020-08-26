#include "../includes/minishell.h"

void get_env(char **env)
{

    int x = env_len(env);
    global_env = (char **)malloc(sizeof(char *) * (x + 1));

    x = 0;
    while (env[++x])
    {
        if (!(global_env[x] = ft_strdup(env[x])))
            free_env(global_env);
    }
    global_env[x] = NULL;
}

int env_len(char **env)
{

    int x = 0;
    while (env[x])
        x++;
    return (x);
}

int start_with(char *s1, char *s2)
{

    int i;

    i = -1;
    while (s2[++i])
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

void print_env()
{

    int x = 0;

    while (global_env[++x])
    {
        ft_putendl(global_env[x]);
    }
}

int ft_setenv(char **args)
{
    if (!args[0])
    {
        print_env();
    }
    if (args[1])
    {
        if (args[2])
        {
            ft_putendl("there are too many arguments.");
            return (1);
        }
    }
    setenv_var(args[0], args[1]);
    return (1);
}

char **ft_renew_env(int pos,char *key, char *value)
{
    char **new_env;
    int x = 0;
    char *tmp;

    new_env = (char **)ft_memalloc(sizeof(char *) * (pos + 1));

    while(global_env[++x] && x < pos)
    {
        new_env[x] = ft_strdup(global_env[x]);
        free(global_env[x]);
    }
    free(global_env);
    tmp = ft_strjoin(key, "=");
    if (value)
        new_env[x] = ft_strjoin(tmp, value);
    else
    {
        new_env[x] = ft_strjoin(key, "=");
    }
    free(tmp);
    return (new_env);
}

int env_position(char *name)
{

    int x;
    char *tmp;

    tmp = ft_strjoin(name, "=");
    x = 0;
    while (global_env[++x])
    {
        if (start_with(global_env[x], tmp))
        {
            free(tmp);
            return (x);
        }
    }
    free(tmp);
    return (x);
}

void setenv_var(char *key, char *value)
{

    int pos;
    char *tmp;

    pos = env_position(key);
    tmp = ft_strjoin("=", value);
    if (global_env[pos])
    {
        free(global_env[pos]);
        if (value)
        {
            global_env[pos] = ft_strjoin(key, tmp);
        }
        else
        {
            global_env[pos] = ft_strjoin(key, "=");
        }
    }
    else
    {
        global_env =  ft_renew_env(pos + 1, key, value);
    }
    free(tmp);
}

static void     ft_remove_env(int pos){

    printf("hello 1");
    int x = 0;
    int count;
    char **new_env;

    count = pos + 1;
    while(global_env[pos + 1]){
        printf("hello 1");
        global_env[pos] = ft_strdup(global_env[pos + 1]);
        pos++;
    }
            printf("hello 2");

    new_env = (char **)ft_memalloc(sizeof(char *) * (count + 1));
            printf("hello 3");

    while (global_env[++x] && x < count)
    {
        new_env[x] =  ft_strdup(global_env[x]);
        free(global_env[x]);
    }
    free(global_env);
    global_env = new_env;
}

int ft_unsetenv(char **args){
    int x = -1;
    int pos;

    if(!args[0]){
        ft_putendl("there are too few arguments.");
        return (1);
    }
    while(args[++x]){
        pos = env_position(args[x]);
        if (global_env[pos])
            ft_remove_env(pos);
    }
    return (1);
}