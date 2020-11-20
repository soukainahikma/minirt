/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:17:17 by shikma            #+#    #+#             */
/*   Updated: 2020/11/19 12:07:13 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_cy_tr(t_element *list, t_raydata *ray, t_vector data, t_object *obj)
{
	double t;

	if (list->id == 8)
	{
		obj->cy = list->obj;
		t = hit_cylinder(data, ray, obj);
	}
	if (list->id == 9)
	{
		obj->triangle = list->obj;
		t = hit_triangle(data, ray, obj);
	}
	return (t);
}

double	inter(t_element *liste, t_raydata *ray, t_vector data, t_object *obj)
{
	double t;

	if (liste->id == 6)
	{
		obj->sphere = liste->obj;
		t = hit_sphere(data, ray, obj);
	}
	if (liste->id == 5)
	{
		obj->plan = liste->obj;
		t = hit_plan(data, ray, obj);
	}
	if (liste->id == 7)
	{
		obj->sq = liste->obj;
		t = hit_sq(data, ray, obj);
	}
	if (liste->id == 8 || liste->id == 9)
		t = hit_cy_tr(liste, ray, data, obj);
	return (t);
}
