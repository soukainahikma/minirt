
#include "minirt.h"
int len_of_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
    {
        i++;
    }
    return (i);
    }
int nb_word(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i++])
    if ((str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\n'
    && str[i - 1] != '\0') && ((str[i - 2] == ' ' ||\
    str[i - 2] == '\t' || str[i - 2] == '\n')
    || i == 1))
    result++;
    return (result);
}

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i;

    i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
return (dest);
}

char **ft_split_whitespaces(char *str)
{
    int i;
    char *tmp;
    char **result;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (!(result = (char**)malloc((sizeof(char*) * nb_word(str)) + 1)))
        return (NULL);
    i = 0;
    while (nb_word(str))
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
        if (!(tmp = (char*)malloc(sizeof(char) * len_of_string(str) + 1)))
            return (NULL);
        ft_strncpy(tmp, str, len_of_string(str));
        tmp[len_of_string(str)] = '\0';
        result[i++] = tmp;
        str += len_of_string(str);
    }
    result[i] = 0;
return (result);
}