#include "../includes/minishell.h"
# include <unistd.h>
#include <stddef.h>
#include "../libft/libft.h"

int val_flags(char **args)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while(args[i][0] != 0)
	{
		if(ft_strcmp(args[i], "echo") == 0)
		{
			while(args[i + j])
			{
				ft_putstr(args[i + j]);
				ft_putstr(" ");
				j++;
			}
			ft_putchar('\n');
			return (1);
		}
		else if (ft_strcmp(args[i], "exit") == 0)
			return(0);
		else
		{
			ft_putstr("Sorry, ");
			ft_putstr(args[i]);
			ft_putendl(" is not a valid command");
			return(1);
		}
	}
	return (1);
}

int set_args(char *line)
{
	char **args;

	if((args = ft_w_split(line)) == NULL)
	{
		return (0);
	}
	else
	{
		if(val_flags(args))
			return (0);
		else
			return (-1);
	}
	return (0);
}
