/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:06:04 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:29:21 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plan	*fill_plan(char **t)
{
	char		**t1;
	char		**t2;
	char		**t3;
	t_plan		*object;

	object = (t_plan *)malloc(sizeof(t_light));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[2], ',');
	t3 = ft_split(t[3], ',');
	object->plan_p.x = ft_atof(t1[0]);
	object->plan_p.y = ft_atof(t1[1]);
	object->plan_p.z = ft_atof(t1[2]);
	object->plan_d.x = ft_atof(t2[0]);
	object->plan_d.y = ft_atof(t2[1]);
	object->plan_d.z = ft_atof(t2[2]);
	object->plan_col.x = ft_atof(t3[0]);
	object->plan_col.y = ft_atof(t3[1]);
	object->plan_col.z = ft_atof(t3[2]);
	free_tab(t1, 3);
	free_tab(t2, 3);
	free_tab(t3, 3);
	return (object);
}
