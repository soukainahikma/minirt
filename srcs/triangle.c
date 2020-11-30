/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:00:26 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:20:16 by shikma           ###   ########.fr       */
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

void	c_cal(t_vector *c, t_vector hit, t_object *obj)
{
	c[0] = soustraction(hit, obj->triangle->tr_p1);
	c[1] = soustraction(hit, obj->triangle->tr_p2);
	c[2] = soustraction(hit, obj->triangle->tr_p3);
}

void	edge_cal(t_vector *edge, t_object *obj)
{
	edge[0] = soustraction(obj->triangle->tr_p2, obj->triangle->tr_p1);
	edge[1] = soustraction(obj->triangle->tr_p3, obj->triangle->tr_p2);
	edge[2] = soustraction(obj->triangle->tr_p1, obj->triangle->tr_p3);
}

double	hit_triangle(t_vector cam, t_raydata *ray_, t_object *obj)
{
	double		t;
	double		denominateur;
	t_vector	edge[3];
	t_vector	norm;
	t_vector	c[3];

	edge_cal(edge, obj);
	norm = get_normalize(cross(edge[0], edge[1]));
	denominateur = dot(ray_->ray_direc[ray_->id], norm);
	if (ft_fabs(denominateur) == 1e-4f)
		return (0);
	t = -dot(soustraction(cam, obj->triangle->tr_p1), norm) / denominateur;
	c_cal(c, ray(cam, ray_->ray_direc[ray_->id], t), obj);
	if (dot(norm, cross(edge[0], c[0])) > 0 && dot(norm,
	cross(edge[1], c[1])) > 0 && dot(norm, cross(edge[2], c[2])) > 0)
	{
		if (t >= 1e-4f)
		{
			ray_->t = t;
			if (ray_->max_d[ray_->id] > t)
				return (tr_cal(cam, ray_, obj, norm));
		}
	}
	return (0);
}
