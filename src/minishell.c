#include "../includes/minishell.h"
#include "../includes/get_next_line.h"

void print_prompt(void)
{
	ft_putstr("\\n||m:");
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
	get_next_line(0, &line);
	
	//set args
	set_args(line);	
	//set statu
	} while (status);
	
	// after do... while... free args and line
}

int main(void)
{
	// load config files
	
	//run command loop
	
	mini_loop();
	
	// perform shutdown/cleanup
	return (0);
}
