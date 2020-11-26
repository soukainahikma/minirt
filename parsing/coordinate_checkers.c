/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:48:55 by shikma            #+#    #+#             */
/*   Updated: 2020/11/26 18:27:10 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_position(char *t)
{
	char **t1;

	t1 = ft_split(t, ',');
	if (is_2_commas(t) == 1 && is_float(t1[0]) == 1
	&& is_float(t1[1]) == 1 && is_float(t1[2]) == 1)
		return (1);
	else
		return (0);
}

int	check_normal(char *t)
{
	char **t1;

	t1 = ft_split(t, ',');
	if (is_2_commas(t) != 1)
		return (0);
	if (-1 > ft_atof(t1[0]) || -1 > ft_atof(t1[1]) || -1 > ft_atof(t1[2])
	|| 1 < ft_atof(t1[0]) || 1 < ft_atof(t1[1]) || 1 < ft_atof(t1[2]))
		return (0);
	if (is_float(t1[0]) == 1 && is_float(t1[1]) == 1
	&& is_float(t1[2]) == 1)
		return (1);
	else
		return (0);
}

int	check_size(char *t)
{
	if (is_float(t) == 1 && ft_atof(t) >= 0)
		return (1);
	else
		return (0);
}

int	check_color(char *t)
{
	char **t1;

	t1 = ft_split(t, ',');
	if (is_2_commas(t) != 1)
		return (0);
	if (0 > ft_atof(t1[0]) || 0 > ft_atof(t1[1]) || 0 > ft_atof(t1[2])
	|| 255 < ft_atof(t1[0]) || 255 < ft_atof(t1[1]) || 255 < ft_atof(t1[2]))
		return (0);
	if (is_float(t1[0]) == 1 && is_float(t1[1]) == 1 && is_float(t1[2]) == 1)
		return (1);
	else
		return (0);
}

int	check_kl_ka_fov_res(int id, char *t)
{
	if (id == 1)
	{
		if (is_float(t) == 1 && ft_atof(t) >= 0 && ft_atof(t) <= 1)
			return (1);
		else
			return (0);
	}
	if (id == 2)
	{
		if (is_float(t) == 1)
			return (1);
		else
			return (0);
	}
	if (id == 3)
	{
		if (is_int(t) == 1 && ft_atof(t) > 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
