/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 09:44:40 by shikma            #+#    #+#             */
/*   Updated: 2020/11/19 09:16:42 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] != '\0' && st2[i] != '\0' && i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	if (((st1[i] == '\0' && st2 != '\0') ||
				(st1[i] != '\0' && st2[i] == '\0')) && i < n)
		return (st1[i] - st2[i]);
	return (0);
}

int		check_extention(char *str)
{
    char *t ;
    t= "rt";
    while(*str)
    {
        if(*str++=='.')
         break;
    }
    if(ft_strncmp(str,t,2) == 0)
    {
        return(1);
    }
return(0);
}
int check_general_error(char **str, int argc)
{
	if(argc == 3)
	{
		if(check_extention(str[1]) == 0)
        	return(-4);
		if(ft_strncmp(str[2],"--save",6)!=0)
			return(-12);
		return(0);
	}
    if(argc != 2)
        return(-5);
    if(check_extention(str[1]) == 0)
        return(-4);
    
    return(0);
}
