/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:57:16 by shikma            #+#    #+#             */
/*   Updated: 2020/11/27 13:03:24 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		calculate_light(t_vector direction, t_object *object,
			t_light *light)
{
	double	dt;

	light->l = get_normalize(soustraction(light->light_p, light->hit));
	dt = 2 * dot(light->normal, light->l);
	light->r = get_normalize(soustraction(multiplication(dt,
	light->normal), light->l));
	light->view_direction = get_normalize(soustraction(object->camera->lookfrom,
	light->hit));
}

t_vector	cal_dif(t_object *object, t_light *light)
{
	t_vector	color;
	double		dt;

	dt = dot(light->normal, light->l);
	dt = dt < 0 ? 0 : dt;
	color.x = (object->obj_col->x / 255) *
	(light->color.x / 255) * dt * light->kl;
	color.y = (object->obj_col->y / 255) *
	(light->color.y / 255) * dt * light->kl;
	color.z = (object->obj_col->z / 255) *
	(light->color.z / 255) * dt * light->kl;
	return (color);
}

t_vector	cal_spec(t_object *object, t_light *light)
{
	t_vector	color;
	double		dt;
	double		alpha;

	alpha = 800;
	dt = dot(light->r, light->view_direction);
	dt = dt < 0 ? 0 : dt;
	color.x = (light->color.x / 255) * pow(dt, alpha);
	color.y = (light->color.y / 255) * pow(dt, alpha);
	color.z = (light->color.z / 255) * pow(dt, alpha);
	return (color);
}

t_vector	cal_am(t_object *object, t_data data)
{
	t_vector am;

	am.x = (data.am->amb_p.x / 255) * (object->obj_col->x / 255);
	am.y = (data.am->amb_p.y / 255) * (object->obj_col->y / 255);
	am.z = (data.am->amb_p.z / 255) * (object->obj_col->z / 255);
	am = multiplication(data.am->ka, am);
	return (am);
}

t_vector	light(t_element *ptr, t_move *move, t_raydata *ray_)
{
	t_vector	color;
	t_element	*list;
	t_light		*l;

	color = cal_am(&move->object, move->data);
	list = move->liste;
	move->object.light->normal = get_normalize(move->object.light->normal);
	while (list != NULL)
	{
		if (list->id == 4)
		{
			l = (t_light *)list->obj;
			if (l->kl != 0)
			{
				l->hit = move->object.light->hit;
				l->normal = move->object.light->normal;
				calculate_light(ray_->ray_direc[0], &move->object, l);
				color = addition(color, cal_spec(&move->object, l));
				color = addition(color, cal_dif(&move->object, l));
			}
		}
		list = list->next;
	}
	color = shadow(ptr, move, color, ray_);
	return (color);
}
