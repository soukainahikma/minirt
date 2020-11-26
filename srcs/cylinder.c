/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:53:19 by shikma            #+#    #+#             */
/*   Updated: 2020/11/26 14:01:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_cyt(t_vector cam, t_object *obj, t_vector oc, t_raydata *ray)
{
	double		t1;
	double		t2;
	double		a;
	double		b;
	double		c;

	a = dot(ray->ray_direc[ray->id], ray->ray_direc[ray->id]) -
	pow(dot(ray->ray_direc[ray->id], obj->cy->cy_d), 2);
	b = 2 * (dot(ray->ray_direc[ray->id], oc) - (dot(ray->ray_direc[ray->id],
	obj->cy->cy_d) * dot(oc, obj->cy->cy_d)));
	c = dot(oc, oc) - pow(dot(oc, obj->cy->cy_d), 2) -
	(obj->cy->diam * obj->cy->diam) / 4;
	if (((b * b) - (4 * a * c)) < 0)
		return (0);
	t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	t2 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	obj->cy->m1 = dot(ray->ray_direc[ray->id], obj->cy->cy_d) * t1 +
	dot(oc, obj->cy->cy_d);
	obj->cy->m2 = dot(ray->ray_direc[ray->id], obj->cy->cy_d) * t2 +
	dot(oc, obj->cy->cy_d);
	if (obj->cy->m1 >= -obj->cy->h/2 && obj->cy->m1 <= obj->cy->h/2)
		obj->cy->m2 = obj->cy->m1;
	if (t2 > t1)
		t2 = t1;
	return (t2);
}

double	hit_cylinder(t_vector cam, t_raydata *ray_, t_object *obj)
{
	double		t2;
	t_vector	oc;

	obj->cy->cy_d = get_normalize(obj->cy->cy_d);
	oc = soustraction(cam, obj->cy->cy_p);
	t2 = calculate_cyt(cam, obj, oc, ray_);
	if (t2 != 0 && obj->cy->m2 >= -obj->cy->h/2
	&& obj->cy->m2 <= obj->cy->h/2)
	{
		ray_->t = t2;
		if (ray_->max_d[ray_->id] > t2 && t2 >= 0)
		{
			obj->light->hit = ray(cam, ray_->ray_direc[ray_->id], t2);
			obj->light->normal = soustraction(obj->light->hit,
			obj->cy->cy_p);
			obj->light->normal = soustraction(obj->light->normal,
			multiplication(obj->cy->m2, obj->cy->cy_d));
			obj->obj_col = malloc(sizeof(t_vector));
			*(obj->obj_col) = obj->cy->cy_col;
			ray_->max_d[ray_->id] = t2;
			return (1);
		}
	}
	return (0);
}
