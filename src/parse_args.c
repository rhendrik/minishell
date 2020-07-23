#include "../includes/minishell.h"
# include <unistd.h>
#include <stddef.h>
#include "../libft/libft.h"

int val_flags(char **args)
{
	int i;
	int j;
	char cwd[1024];

	i = 0;
	j = 1;
	while(args[i][0] != 0)
	{
		if(ft_strcmp(args[i], "echo") == 0)
		{
			if(args[i + 1] != NULL)
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
			else
				ft_putchar('\n');
			return (1);
		}
		else if (ft_strcmp(args[i], "cd") == 0)
			chdir(args[i + 1]);
		else if (ft_strcmp(args[i], "pwd") == 0)
		{
			ft_putendl(getcwd(cwd, sizeof(cwd)));
			return (1);
		}
		else if (ft_strcmp(args[i], "exit") == 0)
			return(0);
		else if(bin_com(args))
		{
			ft_putendl("i hate u:");
			return (1);
		}
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

int bin_com(char **args)
{
	char *command;
	command = find_command(args[0]);
	char *const argv[1024]= {command, args[1]};
	char *env[]={"PATH=/usr/local/sbin/:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games",NULL};

	if(args[0][0] == '/' && args[0][1] == 'b')
	{
		if (fork() == 0)
		{
			execve(args[0], argv, env);
		}
		else
		{
			return(1);
		}
		
	}
	else
		return (1);
	return (1);
}

char *find_command(char *bin_path)
{
	int i;
	char *ret;

	ret = ft_strnew(ft_strlen(bin_path));
	i = ft_strlen(bin_path);
	while(bin_path[i] != '/')
		i--;
	ret = ft_strcpy(ret, &bin_path[i + 1]);
	return (ret);
}
