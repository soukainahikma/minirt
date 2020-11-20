/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:02:22 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 12:06:57 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	trans_cy_sq_li(t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if ((*ptr)->ptr_last->id == 8)
	{
		obj->cy = (t_cylindre *)(*ptr)->ptr_last->obj;
		obj->cy->cy_p = addition(obj->cy->cy_p, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 7)
	{
		obj->sq = (t_sq *)(*ptr)->ptr_last->obj;
		obj->sq->sq_p = addition(obj->sq->sq_p, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 4)
	{
		obj->light_n = (t_light *)(*ptr)->ptr_last->obj;
		obj->light_n->light_p = addition(obj->light_n->light_p, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	trans_sp_tr(t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if ((*ptr)->ptr_last->id == 6)
	{
		obj->sphere = (t_sphere *)(*ptr)->ptr_last->obj;
		obj->sphere->sphere_p = addition(obj->sphere->sphere_p, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 9)
	{
		obj->triangle = (t_triangle *)(*ptr)->ptr_last->obj;
		obj->triangle->tr_p1 = addition(obj->triangle->tr_p1, *obj->tr);
		obj->triangle->tr_p2 = addition(obj->triangle->tr_p2, *obj->tr);
		obj->triangle->tr_p3 = addition(obj->triangle->tr_p3, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	trans_pl_cam(t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if ((*ptr)->ptr_last->id == 5)
	{
		obj->plan = (t_plan *)(*ptr)->ptr_last->obj;
		obj->plan->plan_p = addition(obj->plan->plan_p, *obj->tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	else if ((*c_ptr)->c_ptr_last != NULL)
	{
		obj->camera = (t_camera *)(*c_ptr)->c_ptr_last->cam;
		obj->camera->lookfrom = addition(obj->camera->lookfrom, *obj->tr);
	}
}

void	translate(char **str, t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if (str[0][0] == 't' && str[0][1] == 'r' && str[0][2] == 'a')
	{
		obj->tr = fill_translation(str);
		trans_cy_sq_li(obj, c_ptr, ptr);
		trans_sp_tr(obj, c_ptr, ptr);
		trans_pl_cam(obj, c_ptr, ptr);
	}
}
