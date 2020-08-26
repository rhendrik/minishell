#include "../includes/minishell.h"
# include <unistd.h>
#include <stddef.h>
#include "../libft/libft.h"

int val_flags(char **args)
{
	int i;
	char cwd[1024];

	i=0;
	while(args[i][0] != 0)
	{
		if(ec_echo(args, i))
			return (1);
		else if (ft_strcmp(args[i], "cd") == 0)
			chdir(args[i + 1]);
		else if (ft_strcmp(args[i], "pwd") == 0)
		{
			ft_putendl(getcwd(cwd, sizeof(cwd)));
			return (1);
		}
		else if (ft_strcmp(args[i], "exit") == 0)
			return(0);
		else if(ft_strcmp(args[i], "env") == 0){
			print_env();
			return(1);
		}
		else if(ft_strcmp(args[i], "setenv") == 0){
			return(ft_setenv(args + 1));
		}
		else if(ft_strcmp(args[i], "unsetenv") == 0){
			return(ft_unsetenv(args + 1));
		}
		else if(bin_com(args))
		{
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
			wait(NULL);
			return(1);
		}

	}
	else
		return (0);
	return (0);
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

int ec_echo( char **args, int i)
{
	int j;
	int k;

	j = 1;
	k = 0;
	(void)k;

	if(ft_strcmp(args[i], "echo") == 0)
	{
		if(args[i + 1] != NULL)
		{
			while(args[i + j])
			{
				if(args[1][0] == '"' || (ft_strlen(args[i + j]) == '"' && args[i + j + 1] == NULL))
				{
					args[i+ j][ft_strlen(args[i + j]) - 1] = 0;
					ft_putstr(&args[i + j][1]);
					j++;
					continue;
				}
				else 
				{			
					ft_putstr(args[i + j]);
					ft_putstr(" ");
					j++;

				}

			}
		}
		ft_putchar('\n');
		return (1);
	}
	else
		return (0);
	return (0);
}

