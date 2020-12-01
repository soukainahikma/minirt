/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:33:50 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 20:07:57 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	n1(char *s, double *n1, double *n2, int *sign)
{
	int i;

	(*n1) = 0;
	i = 0;
	if (s[i] == '-')
		*sign = -1;
	while (s[i] != '\0' && s[i] != '.')
	{
		if ((s[i] >= 48) && (s[i] <= 57))
			(*n1) = (*n1) * 10 + (s[i] - 48);
		i++;
	}
	i++;
	(*n2) = 0;
	while (s[i])
	{
		if ((s[i] >= 48) && (s[i] <= 57))
			(*n2) = (*n2) * 10 + (s[i] - 48);
		i++;
	}
	return (*n2);
}

double	ft_atof(char *s)
{
	int		t;
	int		c;
	double	f1;
	double	f2;
	int		sign;

	sign = 1;
	c = 1;
	t = n1(s, &f1, &f2, &sign);
	while (t)
	{
		t = t / 10;
		c = c * 10;
	}
	f2 = f2 / c;
	return (sign * (f1 + f2));
}
