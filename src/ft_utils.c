#include "../includes/minishell.h"




char	*ft_strjoinch(char *s1, char c)
{
	size_t	x = 0;
	size_t	len = ft_strlen(s1);;
	char	*str = ft_strnew(len + 1);

	if (!s1 || !c)
		return (NULL);
	if (!str)
		return (NULL);
	while (x < len){
		*(str + x) = *(s1 + x);
		x++;
	}
	*(str + x) = c;
	return (str);
}

char		*ft_strjoinchf(char *str, char c)
{
	char	*new;

	new = ft_strjoinch(str, c);
	if (!new)
		return (NULL);
	free(str);
	str = NULL;
	return (new);
}

