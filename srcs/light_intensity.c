/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:57:16 by shikma            #+#    #+#             */
/*   Updated: 2020/11/22 09:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			check_distance(t_vector origin, t_vector light, t_vector object)
{
	double	a;
	double	b;

	a = norm(soustraction(origin, light));
	b = norm(soustraction(origin, object));
	if (a > b)
		return (1);
	return (0);
}

void		calculate_light(t_vector direction, t_object *obj, t_vector li_p)
{
	obj->light_n->view_direction = multiplication(-1, direction);
	obj->light_n->view_direction = get_normalize(obj->light_n->view_direction);
	obj->light_n->normal = get_normalize(obj->light_n->normal);
	obj->light_n->light = soustraction(li_p, obj->light_n->light);
	obj->light_n->light = get_normalize(obj->light_n->light);
}

t_vector	dif_spe(t_object **obj, t_light *l)
{
	double		dt;
	t_sun		sun;
	t_vector	r;
	t_vector	color;

	color = (t_vector){0, 0, 0};
	dt = dot((*obj)->light_n->light, (*obj)->light_n->normal);
	dt = dt < 0 ? 0 : dt;
	sun.diffuse.x = ((*obj)->obj_col->x / 255) * (l->color.x / 255) *
	dt * l->kl;
	sun.diffuse.y = ((*obj)->obj_col->y / 255) * (l->color.y / 255) *
	dt * l->kl;
	sun.diffuse.z = ((*obj)->obj_col->z / 255) * (l->color.z / 255) *
	dt * l->kl;
	r = soustraction(multiplication(2 * dt, (*obj)->light_n->normal),
	(*obj)->light_n->light);
	dt = dot(r, (*obj)->light_n->view_direction);
	dt = dt < 0 ? 0 : dt;
	sun.specular.x = ((l->color.x / 255) * pow(dt, 1000));
	sun.specular.y = ((l->color.y / 255) * pow(dt, 1000));
	sun.specular.z = ((l->color.z / 255) * pow(dt, 1000));
	color.x += sun.diffuse.x + sun.specular.x;
	color.y += sun.diffuse.y + sun.specular.y;
	color.z += sun.diffuse.z + sun.specular.z;
	return (color);
}

t_vector	cal_am(t_object *obj, t_data data)
{
	t_sun sun;

	obj->shd_col = obj->obj_col;
	obj->shd->ks = data.am->ka;
	sun.ambiant.x = (data.am->amb_p.x / 255) * (obj->obj_col->x / 255);
	sun.ambiant.y = (data.am->amb_p.y / 255) * (obj->obj_col->y / 255);
	sun.ambiant.z = (data.am->amb_p.z / 255) * (obj->obj_col->z / 255);
	sun.ambiant = multiplication(data.am->ka, sun.ambiant);
	return (sun.ambiant);
}

t_vector	light(t_element *ptr, t_object *obj, t_data data, t_raydata ray_)
{
	t_sun		sun;
	t_vector	color;
	t_element	*liste;
	t_light		*l;

	liste = ptr;
	color = (t_vector){0, 0, 0};
	obj->shd = malloc(sizeof(t_shd));
	obj->shd->shd_p = addition(obj->light_n->light,
	multiplication(1e-4f, obj->light_n->normal));
	sun.ambiant = cal_am(obj, data);
	if (obj->light_n->kl == 0)
		return (color);
	while (liste != NULL)
	{
		if (liste->id == 4)
		{
			l = (t_light*)liste->obj;
			calculate_light(ray_.ray_direc[ray_.id], obj, l->light_p);
			color = addition(color, dif_spe(&obj, l));
		}
		liste = liste->next;
	}
	color = addition(color, sun.ambiant);
	return (color);
}
