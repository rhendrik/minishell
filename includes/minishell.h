#ifndef _MINISHELL_H_
#define _MINISHELL_H_

# include "../libft/libft.h"
# include "./get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

char    **global_env;


void    mini_loop(void);
int     set_args(char *line);
char    **ft_w_split(const char *s);
char *find_command(char *bin_path);
int bin_com(char **args);
int ec_echo( char **args, int i);


//environmnet
void    get_env(char **env);
int     env_len(char **env);
void     print_env();
int     ft_setenv(char **args);
void   setenv_var(char *key, char *value);
void ft_envVariable(char *name, char *new_value);
char      **ft_renew_env(int re);
int     env_position(char *name);

//free
void    free_env(char **env);
int     env_position(char *name);

#endif
