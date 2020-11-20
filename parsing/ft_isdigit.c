
#include "minirt.h"

int		ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
		return (0);
}

int     is_float(char *t)
{
    size_t i;
    int k;

    k = 0;
    i = 0;
    if(t[0] == '-' || t[0] == '+')
        i = 1;
    while(i < ft_strlen(t))
    {
        if(t[i] == '.' && k == 0)
        {
            k = 1;
            i++;
        }
        if(ft_isdigit(t[i]) == 0)
            return(0);
        i++;
    }
    return(1);
}

int is_2_commas(char *t)
{
    size_t i;
    int k;

    k = 0;
    i=0;
    while(i++<=ft_strlen(t))
    {
        if(t[i]==',')
            k++;
    }
    if(k == 2)
        return(1);
    else
        return(0);
}
int     is_int(char *t)
{
    size_t i;

    i = 0;
    if(t[0] == '-' || t[0] == '+')
        i = 1;
    while(i < ft_strlen(t))
    {
        if(t[i] == '.')
            break;
        if(ft_isdigit(t[i]) == 0)
            return(0);
        i++;
    }
    i++;
    while(i < ft_strlen(t))
    {
        if(t[i] != '0')
            return(0);
        i++;
    }
    return(1);
}
void		ft_putstr_fd(char *s, int fd)
{
	int			i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}