/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:57:16 by shikma            #+#    #+#             */
/*   Updated: 2020/11/24 16:59:01 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double			check_distance(t_vector origin, t_vector light, t_vector object,t_vector cam)
{
	double	a;
	double	b;
	t_vector c;
	t_vector d;
	double dt;

	a = norm(soustraction(origin, light));
	b = norm(soustraction(origin, object));
	c = cam;
	d = soustraction(light,origin);
	if (a >= b)
	{
		if(dot(c,d)<0)
			return (1);
	}
	return (0);
}

void		calculate_light(t_vector direction, t_object *object, t_vector li_p)
{
	
}

t_vector	dif_spe(t_object **object, t_light *l)
{
	double		dt;
	t_sun		sun;
	t_vector hit;
	t_vector	r;
	t_vector	color;

	hit = soustraction(l->light_p, (*object)->light->hit);
	hit = get_normalize(hit);
	color = (t_vector){0, 0, 0};
	dt = dot(hit, (*object)->light->normal);
	dt = dt < 0 ? 0 : dt;
	sun.diffuse.x = ((*object)->obj_col->x / 255) * (l->color.x / 255) *
	dt * l->kl;
	sun.diffuse.y = ((*object)->obj_col->y / 255) * (l->color.y / 255) *
	dt * l->kl;
	sun.diffuse.z = ((*object)->obj_col->z / 255) * (l->color.z / 255) *
	dt * l->kl;
	r = soustraction(multiplication(2 * dt, (*object)->light->normal),
	hit);
	dt = dot(r, (*object)->light->view_direction);
	dt = dt < 0 ? 0 : dt;
	sun.specular.x = ((l->color.x / 255) * pow(dt, 1000));
	sun.specular.y = ((l->color.y / 255) * pow(dt, 1000));
	sun.specular.z = ((l->color.z / 255) * pow(dt, 1000));
	color.x = sun.diffuse.x + sun.specular.x;
	color.y = sun.diffuse.y + sun.specular.y;
	color.z = sun.diffuse.z + sun.specular.z;
	return (color);
}

t_vector	cal_am(t_object *object, t_data data)
{
	t_sun sun;

	//object->shd_col = object->obj_col;
	//object->shd->ks = data.am->ka;
	sun.ambiant.x = (data.am->amb_p.x / 255) * (object->obj_col->x / 255);
	sun.ambiant.y = (data.am->amb_p.y / 255) * (object->obj_col->y / 255);
	sun.ambiant.z = (data.am->amb_p.z / 255) * (object->obj_col->z / 255);
	sun.ambiant = multiplication(data.am->ka, sun.ambiant);
	return (sun.ambiant);
}

t_vector	light(t_element *ptr, t_object *object, t_data data, t_raydata ray_)
{
	t_sun		sun;
	t_vector	color;
	t_vector    test;
	t_vector	hit;
	t_element	*liste;
	t_light		*l;

	liste = ptr;
	color = (t_vector){0, 0, 0};
	test = (t_vector){0, 0, 0};
	color = cal_am(object, data);
	if (object->light->kl == 0)
		return (color);
	object->light->view_direction = soustraction(object->camera->lookfrom,(object->light->hit));
	object->light->view_direction = get_normalize(object->light->view_direction);
	object->light->normal = get_normalize(object->light->normal);
	l = (t_light *)malloc(sizeof(t_light));
	while (liste != NULL)
	{
		if (liste->id == 4)
		{
			l = (t_light*)liste->obj;
			
			test = addition(test, dif_spe(&object, l));
		}
		liste = liste->next;
	}
	color = addition(color, test);
	return (color);
}
