#include "../includes/minishell.h"
#include "../includes/get_next_line.h"

void print_prompt(void)
{
	ft_putstr("i hate u: ");
}

void mini_loop(void)
{
	//declare line, args and status
	int status;
	char *line;

	status = 1;
	//do... while loop
	do {
	
	//print prompt
	print_prompt();	

	//read line
	
	if(!get_next_line(0, &line))
	{
		ft_putchar('\n');
		continue;
	}
	else 	
	{
		//set args
		if(ft_strcmp(line, "") == 0)
			continue;	
		else
			if(set_args(line) == -1){
				status = 0;
				free_env(global_env);
			}
	}
	//set statu
	} while (status);
	
	// after do... while... free args and line
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv	;
	get_env(env);
	//run command loop
	
	mini_loop();
	
	// perform shutdown/cleanup
	return (0);
}
