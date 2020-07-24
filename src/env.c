#include "../includes/minishell.h"

void    get_env(char **env){

    int x = env_len(env);
    global_env = (char **)malloc(sizeof(char *) * (x + 1));

    x = 0;
    while (env[++x]){
        if (!(global_env[x] = ft_strdup(env[x])))
            free_env(global_env);
        }
    global_env[x] = NULL;
}

int  env_len(char **env){

	int	    x = 0;
	while (env[x])
		x++;
	return (x);
}

 void print_env(){

    int x = 0;

    while (global_env[++x])
    {
        ft_putendl(global_env[x]); 
    }
 }

 int    ft_setenv(char **args) {
     
     if(!args[1]){
         print_env();
     }
     else if(args[3]){
         ft_putendl("there are too many arguments.");
     }

     else if(args[2]){
         setenv_var(args[1], args[2]);
     }
     return (1);
 }

void ft_envVariable(char *name, char *new_value){

     int x = 0;
     char *new_env;
     char *tmp;

     new_env = strdup(name);
     tmp = new_env;
     new_env = ft_strjoin(new_value, "=");
     free(tmp);

    new_env = ft_strjoin(new_env, new_value);
    x = env_position(name);
    if(x != -1){
        global_env[x] = new_env;
    }
    else{
        global_env = ft_renew_env(x + 1);
    }
 }

char      **ft_renew_env(int re){

     char **new_env;
     int x = 0;

    new_env = (char **)ft_memalloc(sizeof(char *) * (re + 1));
    x = -1;
    while(global_env[++x] && x < re) {
        new_env[x] = ft_strdup(global_env[x]);
        free(global_env[x]);
    }
    free(global_env);
    return(new_env);
 }

int     env_position(char *name){

     int x = 0;
     while(global_env[x] != NULL){
        if (ft_strncmp(global_env[x], name, ft_strlen(name)) == 0)
           return x;
        x++; 
     }
     return(-1);
 }

 void   setenv_var(char *key, char *value) {

     char *v_name;
     char *v_value;
     int x = 0;

     while(value[x] != '=')
        x++;
    v_name = ft_strndup(value, x);
    ft_putendl(v_name);
    v_value = ft_strdup(value + (x + 1));
    ft_putendl(v_value);
    ft_envVariable(v_name, v_value);
    free(v_value);
    free(v_name);
 }