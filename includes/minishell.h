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


//environmnet
void    get_env(char **env);
int     env_len(char **env);
void     print_env();
int     ft_setenv(char **args);
//free
void    free_env(char **env);
#endif
