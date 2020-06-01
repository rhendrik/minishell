#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t line_count = 0;
	char *line = NULL;

	int fd = open("Makefile", O_RDONLY);	
	while(get_next_line(fd, &line))
	{
		line_count++;
		ft_putendl(line);
		free(line);
	}
	return (0);
}
