/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:33:50 by shikma            #+#    #+#             */
/*   Updated: 2020/11/26 18:37:41 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	n1(char *s, double *n1, double *n2)
{
	int i;
	int sign;

	sign = 1;
	(*n1) = 0;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	while (s[i] != '\0' && s[i] != '.')
	{
		if ((s[i] >= 48) && (s[i] <= 57))
			(*n1) = (*n1) * 10 + (s[i] - 48);
		i++;
	}
	(*n1) = sign * (*n1);
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

	c = 1;
	t = n1(s, &f1, &f2);
	while (t)
	{
		t = t / 10;
		c = c * 10;
	}
	f2 = f2 / c;
	return (f1 + f2);
}
