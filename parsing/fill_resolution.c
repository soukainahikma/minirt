/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:11:42 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:09:44 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_resolution	fill_resolution(char **t)
{
	t_resolution res;

	res.w = ft_atof(t[1]);
	res.h = ft_atof(t[2]);
	return (res);
}

t_vector		fill_rotation(char **t)
{
	char		**t1;
	t_vector	rot;

	t1 = ft_split(t[1], ',');
	rot.x = ft_atof(t1[0]);
	rot.y = ft_atof(t1[1]);
	rot.z = ft_atof(t1[2]);
	free_tab(t1,3);
	return (rot);
}

t_vector		fill_translation(char **t)
{
	char		**t1;
	t_vector	tr;

	t1 = ft_split(t[1], ',');
	tr.x = ft_atof(t1[0]);
	tr.y = ft_atof(t1[1]);
	tr.z = ft_atof(t1[2]);
	free_tab(t1,3);
	return (tr);
}
