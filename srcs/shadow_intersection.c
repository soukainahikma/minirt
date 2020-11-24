/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:17:37 by shikma            #+#    #+#             */
/*   Updated: 2020/11/24 16:57:19 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		sh_cal(t_light **l, t_object *obj, t_raydata *ray, t_element *lst)
{

	(*l) = (t_light*)lst->obj;
	obj->shd->shd_d = soustraction((*l)->light_p,
	obj->shd->shd_p);
	obj->shd->shd_d = addition(obj->shd->shd_d,
	(t_vector){1e-4f, 1e-4f, 1e-4f});
	ray->ray_direc[1] = obj->shd->shd_d;
	ray->id = 1;
}

t_vector	sh_col(t_light *l, t_move *move)
{
	t_vector col;

	col = (t_vector){0, 0, 0};
	col = multiplication(0,
	division(255, *(move->object.shd_col)));
	return (col);
}

t_vector	shadow(t_element *list, t_move *all, t_vector col, t_raydata ray,int *t2)
{
	double		t[2];
	t_element	*li[2];
	t_light		*l;
	t_vector	tx;
	
	li[0] = all->liste;
	all->object.shd = malloc(sizeof(t_shd));
	tx = all->object.light->hit;
	all->object.shd->shd_p = all->object.light->hit;
	while (li[0] != NULL)
	{
		ray.max_d[1] = INT_MAX;
		li[1] = all->liste;
		t[1] = 0;
		if(li[0]->id != 4)
		{
			while (li[1] != NULL)
			{
				if (li[1]->id == 4 && li[0] != list)
			{
				l = (t_light*)li[1]->obj;
				all->object.shd->shd_d = soustraction(l->light_p,
				all->object.shd->shd_p);
				all->object.shd->shd_d = addition(all->object.shd->shd_d,
				(t_vector){1e-4f, 1e-4f, 1e-4f});
				ray.ray_direc[1] = all->object.shd->shd_d;
				ray.id = 1;
				t[0] = inter(li[0], &ray, tx, &all->object);
				if(t[0] == 1)
				{
					//t[1] = check_distance(all->object.shd->shd_p, 
					//l->light_p, all->object.light->hit,ray.ray_direc[0]);
					//if (t[1] == 1 )
					//{
				//		*t2 = 1;
						col = (t_vector){0,0,0};
						return(col);
				//	}				
				}
				
			}
			li[1] = li[1]->next;
		}
		}
		li[0] = li[0]->next;

	}
	return (col);
}
