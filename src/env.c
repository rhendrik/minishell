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

int start_with(char *to_start, char *str)
{

	int		i;

	i = 0;
	while (to_start[i] && str[i] && (to_start[i] == str[i]))
		i++;
	return (to_start[i] == '\0' ? 1 : 0);
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
char		*ft_getenv(char *key)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(key, "=");
	while (global_env[++i])
	{
		if (start_with(temp, global_env[i]))
		{
			free(temp);
			return (ft_strchr(global_env[i], '=') + 1);
		}
	}
	free(temp);
	return (NULL);
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

static void  ft_remove_env(int pos){

    int x = 0;
    int count;
    char **new_env;

    free(global_env[pos]);
    global_env[pos] = NULL;
    count = pos + 1;
    while(global_env[pos + 1]){
        global_env[pos] = ft_strdup(global_env[pos + 1]);
        free(global_env[pos + 1]);
        count++;
        pos++;
    }

    count = count - 1;
    new_env = (char **)ft_memalloc(sizeof(char *) * (count + 1));

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
        if (global_env[pos]){
            ft_remove_env(pos);
        }
    }
    return (1);
}

