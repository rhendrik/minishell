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

void mini_loop(void);
int set_args(char *line);
char                    **ft_w_split(const char *s);

#endif
