/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:17:37 by shikma            #+#    #+#             */
/*   Updated: 2020/11/21 10:43:36 by shikma           ###   ########.fr       */
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
	col = multiplication(l->kl * move->object.shd->ks,
	division(255, *(move->object.shd_col)));
	return (col);
}

t_vector	shadow(t_element *list, t_move *all, t_vector col, t_raydata ray)
{
	double		t[2];
	t_element	*li[2];
	t_light		*l;

	ray.max_d[1] = INT_MAX;
	li[0] = all->liste;
	while (li[0] != NULL)
	{
		if (li[0]->id == 4)
		{
			sh_cal(&l, &all->object, &ray, li[0]);
			li[1] = all->liste;
			while (li[1] != NULL)
			{
				t[0] = inter(li[1], &ray, all->object.shd->shd_p, &all->object);
				t[1] = check_distance(all->object.shd->shd_p,
				l->light_p, all->object.light_n->light);
				if (t[0] == 1 && t[1] == 1 && li[1] != list)
					return (sh_col(l, all));
				li[1] = li[1]->next;
			}
		}
		li[0] = li[0]->next;
	}
	return (col);
}
