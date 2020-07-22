#include "../includes/minishell.h"

void    get_env(char **env){

    int x = env_len(env);
    global_env = (char **)malloc(sizeof(char *) * (x + 1));

    x = 0;
    while (env[++x]){
        printf("hello");
        if (!(global_env[x] = ft_strdup(env[x])))
            free_env(global_env);
        }
}

int  env_len(char **env){

	int	    x = 0;
	while (env[x])
		x++;
	return (x);
}