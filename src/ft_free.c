#include "../includes/minishell.h"

void    free_env(char **env){
    int x = 0;
    while (env[++x])
    {
        free(env[x]);
    }
    free(env);
    env = NULL;
    exit(0);
}
