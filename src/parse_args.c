#include "../includes/minishell.h"

int set_args(char *line)
{
	char **args;

	args = ft_w_split(line);
	if(args != NULL)
	{
		if(ft_strcmp(args[0], "") != 0)
			ft_putendl(args[0]);
		else
			ft_putstr(args[0]);
	}
	else
		return (0);
	return (0);
}
