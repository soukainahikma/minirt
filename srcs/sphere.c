/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:22:02 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:18:53 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_spt(t_object *obj, t_vector oc, t_raydata *ray_)
{
	double		t1;
	double		t2;
	double		a;
	double		b;
	double		c;

	a = dot(ray_->ray_direc[ray_->id], ray_->ray_direc[ray_->id]);
	b = 2 * dot(oc, ray_->ray_direc[ray_->id]);
	c = dot(oc, oc) - ((obj->sphere->diametre * obj->sphere->diametre) / 4);
	if ((b * b) - (4 * a * c) < 0)
		return (-1);
	t1 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
	t2 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
	if (t2 > t1)
		t2 = t1;
	return (t2);
}

double	hit_sphere(t_vector cam, t_raydata *ray_, t_object *obj)
{
	double		t1;
	t_vector	oc;

	oc = soustraction(cam, obj->sphere->sphere_p);
	t1 = calculate_spt(obj, oc, ray_);
	if (t1 >= 0)
	{
		ray_->t = t1;
		if (t1 < ray_->max_d[ray_->id])
		{
			ray_->max_d[ray_->id] = t1;
			obj->light->hit = ray(cam, ray_->ray_direc[ray_->id], t1);
			obj->light->normal = soustraction(obj->light->hit,
			obj->sphere->sphere_p);
			obj->obj_col = obj->sphere->sphere_col;
			return (1);
		}
	}
	return (0);
}
