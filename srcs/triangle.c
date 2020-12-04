/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:32:42 by shikma            #+#    #+#             */
/*   Updated: 2020/12/04 14:23:46 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		tr_cal(t_vector cam, t_raydata *ray_, t_object *obj, t_vector norm)
{
	obj->light->hit = ray(cam, ray_->ray_direc[ray_->id], ray_->t);
	if (dot(ray_->ray_direc[ray_->id], norm) <= 0)
		obj->light->normal = norm;
	else
		obj->light->normal = multiplication(-1, norm);
	obj->obj_col = obj->triangle->tr_col;
	ray_->max_d[ray_->id] = ray_->t;
	return (1);
}

double	hit_triangle(t_vector cam, t_raydata *ray_, t_object *obj)
{
	t_tr_help help;

	help.edge1 = soustraction(obj->triangle->tr_p2, obj->triangle->tr_p1);
	help.edge2 = soustraction(obj->triangle->tr_p3, obj->triangle->tr_p1);
	help.h = cross(ray_->ray_direc[ray_->id], help.edge2);
	help.a = dot(help.edge1, help.h);
	if (help.a > -0.0000001 && help.a < 0.0000001)
		return (0);
	help.f = 1.0 / help.a;
	help.s = soustraction(cam, obj->triangle->tr_p1);
	help.u = help.f * (dot(help.s, help.h));
	if (help.u < 0.0 || help.u > 1.0)
		return (0);
	help.q = cross(help.s, help.edge1);
	help.v = help.f * dot(ray_->ray_direc[ray_->id], help.q);
	if (help.v < 0.0 || help.u + help.v > 1.0)
		return (0);
	help.t = dot(help.edge2, help.q) * help.f;
	if (help.t <= 0.0000001)
		return (0);
	ray_->t = help.t;
	if (ray_->max_d[ray_->id] > help.t)
		return (tr_cal(cam, ray_, obj, cross(help.edge1, help.edge2)));
	return (0);
}
