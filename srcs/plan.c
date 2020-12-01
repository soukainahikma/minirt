/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:27:21 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:45:49 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	plan_cal(t_vector cam, t_raydata *ray_, t_object *obj)
{
	obj->light->hit = ray(cam, ray_->ray_direc[ray_->id], ray_->t);
	if (dot(ray_->ray_direc[ray_->id], obj->plan->plan_d) <= 0)
		obj->light->normal = obj->plan->plan_d;
	else
		obj->light->normal = multiplication(-1, obj->plan->plan_d);
	obj->obj_col = obj->plan->plan_col;
	ray_->max_d[ray_->id] = ray_->t;
}

double	hit_plan(t_vector cam, t_raydata *ray_info, t_object *obj)
{
	double		t;
	double		denominateur;
	double		b;
	t_vector	oc;

	obj->plan->plan_d = get_normalize(obj->plan->plan_d);
	denominateur = dot(ray_info->ray_direc[ray_info->id], obj->plan->plan_d);
	oc = soustraction(cam, obj->plan->plan_p);
	b = -dot(oc, obj->plan->plan_d);
	if (denominateur == 1e-4f)
		return (0);
	t = b / denominateur;
	if (t > 0)
	{
		ray_info->t = t;
		if (ray_info->max_d[ray_info->id] > t)
		{
			plan_cal(cam, ray_info, obj);
			return (1);
		}
	}
	return (0);
}
