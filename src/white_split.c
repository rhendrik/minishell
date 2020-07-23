#include "../includes/minishell.h"

int ft_is_wspc(char c)
{
	if (c == ' ')
		return(1);
	else if(c == '\t')
		return (1);
	return (0);
}

static int              ft_countwords(char const *str)
{
        int count;
        int     i;

        i = 0;
        count = 0;
        while (str[i])
        {
                while (ft_is_wspc(str[i]))
                        i++;
                if (!ft_is_wspc(str[i]) && str[i] != '\0')
                        count++;
                while (!ft_is_wspc(str[i]) && str[i] != '\0')
                        i++;
        }
        return (count);
}

static int              get_word_len(char const *str)
{
        int     i;
        int     len;

        i = 0;
        len = 0;
        while (ft_is_wspc(str[i]))
                i++;
        while (!ft_is_wspc(str[i]) && str[i] != '\0')
        {
                i++;
                len++;
        }
        return (len);
}

char                    **ft_w_split(const char *s)
{
        int             i;
        int             j;
        int             k;
        char    **ret;

        if (!s || !(ret = (char **)malloc(sizeof(*ret) *
                (ft_countwords(s) + 1))))
                return (NULL);
	if(ft_countwords(s) == 0)
		return (NULL);
        i = -1;
        j = 0;
        while (++i < ft_countwords(s))
        {
                k = 0;
                if (!(ret[i] = ft_strnew(get_word_len(&s[j]) + 1)))
                        ret[i] = NULL;
                while (ft_is_wspc(s[j]))
                        j++;
                while (!ft_is_wspc(s[j]) && s[j])
                        ret[i][k++] = s[j++];
                ret[i][k] = '\0';
        }
        ret[i] = NULL;
        return (ret);
}
                                                  
