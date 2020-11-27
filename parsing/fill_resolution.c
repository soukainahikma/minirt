/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:11:42 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 19:37:26 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_resolution	*fill_resolution(char **t)
{
	t_resolution *res;

	res = (t_resolution *)malloc(sizeof(t_resolution));
	res->w = ft_atof(t[1]);
	res->h = ft_atof(t[2]);
	return (res);
}

t_vector		*fill_rotation(char **t)
{
	char		**t1;
	t_vector	*rot;

	rot = (t_vector *)malloc(sizeof(t_vector));
	t1 = ft_split(t[1], ',');
	rot->x = ft_atof(t1[0]);
	rot->y = ft_atof(t1[1]);
	rot->z = ft_atof(t1[2]);
	return (rot);
}

t_vector		*fill_translation(char **t)
{
	char		**t1;
	t_vector	*tr;

	tr = (t_vector *)malloc(sizeof(t_vector));
	t1 = ft_split(t[1], ',');
	tr->x = ft_atof(t1[0]);
	tr->y = ft_atof(t1[1]);
	tr->z = ft_atof(t1[2]);
	return (tr);
}
