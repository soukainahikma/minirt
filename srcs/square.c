/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:10:29 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:44:49 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		sq_cal(t_vector cam, t_raydata *ray_, t_object *obj)
{
	obj->light->hit = ray(cam, ray_->ray_direc[ray_->id], ray_->t);
	if (dot(ray_->ray_direc[ray_->id], obj->sq->sq_d) <= 0)
		obj->light->normal = obj->sq->sq_d;
	else
		obj->light->normal = multiplication(-1, obj->sq->sq_d);
	obj->obj_col = obj->sq->sq_col;
	ray_->max_d[ray_->id] = ray_->t;
	return (1);
}

double	hit_sq(t_vector cam, t_raydata *ray_, t_object *obj)
{
	double		t;
	double		denominateur;
	double		b;
	t_vector	oc;
	t_vector	vec[2];

	obj->sq->sq_d = get_normalize(obj->sq->sq_d);
	vec[0] = cross((t_vector){0, 1, 0}, obj->sq->sq_d);
	vec[1] = cross(obj->sq->sq_d, vec[0]);
	denominateur = dot(ray_->ray_direc[ray_->id], obj->sq->sq_d);
	oc = soustraction(cam, obj->sq->sq_p);
	b = -dot(oc, obj->sq->sq_d);
	if (ft_fabs(denominateur) == 1e-4f)
		return (0);
	t = b / denominateur;
	oc = soustraction(obj->sq->sq_p,
	ray(cam, ray_->ray_direc[ray_->id], t));
	if (ft_fabs(dot(oc, vec[0]) / (double)(obj->sq->side_size / 2)) <= 1 &&
	ft_fabs(dot(oc, vec[1]) / (double)(obj->sq->side_size / 2)) <= 1 && t >= 0)
	{
		ray_->t = t;
		if (ray_->max_d[ray_->id] > t)
			return (sq_cal(cam, ray_, obj));
	}
	return (0);
}
