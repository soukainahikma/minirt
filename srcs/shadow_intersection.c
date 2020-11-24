/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:17:37 by shikma            #+#    #+#             */
/*   Updated: 2020/11/24 20:52:12 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int call_light(t_element *liste_light,t_element *list_obj,t_move *all)
{
	t_raydata ray;
	t_element *list;
	double t1;
	double t2;
	t_light *l;
	t_vector new_start;

	ray.max_d[1] = INT_MAX;
	ray.id = 1;
	list = liste_light;
	new_start = addition(all->object.light->hit,multiplication(1e-4f, all->object.light->normal));
	while(list != NULL)
	{
		if(list->id == 4)
		{
			l = (t_light *)list->obj;
			ray.ray_direc[1] = soustraction(l->light_p, all->object.light->hit);
			t1 = inter(list_obj, &ray, all->object.light->hit, &all->object);
			all->object.light->hit = soustraction(all->object.light->hit,(t_vector){1e-4f,1e-4f,1e-4f});
			if(t1 == 1)
			{
				t2 = check_distance(new_start,l->light_p,all->object.light->hit,all->object.camera->cam_d);
				if(t2 == 1)
					return(1);
			}
		}
		list = list->next;
	}
	return(0);
}
t_vector	shadow(t_element *list, t_move *all, t_vector col)
{
	t_element *list_obj;
	
	
	list_obj = all->liste;
	
	while(list_obj != NULL)
	{
		if(list_obj != list)
		{
			if(call_light(all->liste,list_obj,all) == 1)
			return((t_vector){0,0,0});
		}
		list_obj = list_obj->next;
	}
	return(col);
}
