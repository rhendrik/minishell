#include "../includes/minishell.h"

int set_args(char *line)
{
	char **args;

	args = ft_w_split(line);
	ft_putendl(args[0]);
	return (0);
}
