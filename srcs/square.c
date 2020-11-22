/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:10:29 by shikma            #+#    #+#             */
/*   Updated: 2020/11/22 12:05:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sq_cal(t_vector cam, t_raydata *ray_, t_object *obj)
{
	obj->light_n->light = ray(cam, ray_->ray_direc[ray_->id], ray_->t);
	if (dot(ray_->ray_direc[ray_->id], obj->sq->sq_d) <= 0)
		obj->light_n->normal = obj->sq->sq_d;
	else
		obj->light_n->normal = multiplication(-1, obj->sq->sq_d);
	obj->obj_col = malloc(sizeof(t_vector));
	*(obj->obj_col) = obj->sq->sq_col;
	ray_->max_d[ray_->id] = ray_->t;
	return (1);
}

double	hit_sq(t_vector cam, t_raydata *ray_, t_object *obj)
{
	double		t;
	double		denominateur;
	double		b;
	t_vector	oc;
	
	t_vector	u;
	t_vector	v;
	
	obj->sq->sq_d = get_normalize(obj->sq->sq_d);
	u = cross((t_vector){0,1,0},obj->sq->sq_d);
	v = cross(obj->sq->sq_d,u);
	
	denominateur = dot(ray_->ray_direc[ray_->id], obj->sq->sq_d);
	oc = soustraction(cam, obj->sq->sq_p);
	b = -dot(oc, obj->sq->sq_d);
	if (fabs(denominateur) > 1e-4f)
	{
		t = b / denominateur;
		oc = soustraction(obj->sq->sq_p,
		ray(cam, ray_->ray_direc[ray_->id], t));
		if (fabs(dot(oc,u)/ (double)(obj->sq->side_size / 2)) <= 1 && fabs(dot(oc,v)/(double)(obj->sq->side_size / 2)) <= 1 && t >= 1e-4f)
		{
			ray_->t = t;
			if (ray_->max_d[ray_->id] > t)
				return (sq_cal(cam, ray_, obj));
		}
	}
	return (0);
}
