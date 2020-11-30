/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_translation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:02:22 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 12:40:50 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	trans_cy_sq_li(t_vector tr, t_cam_elm **c_ptr, t_element **ptr)
{
	t_cylindre *cy;
	t_sq	*sq;
	t_light *light;
	if ((*ptr)->ptr_last->id == 8)
	{
		cy = (t_cylindre *)(*ptr)->ptr_last->obj;
		cy->cy_p = addition(cy->cy_p, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 7)
	{
		sq = (t_sq *)(*ptr)->ptr_last->obj;
		sq->sq_p = addition(sq->sq_p, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 4)
	{
		light = (t_light *)(*ptr)->ptr_last->obj;
		light->light_p = addition(light->light_p, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	trans_sp_tr(t_vector tr, t_cam_elm **c_ptr, t_element **ptr)
{
	t_sphere *sphere;
	t_triangle *tri;
	if ((*ptr)->ptr_last->id == 6)
	{
		sphere = (t_sphere *)(*ptr)->ptr_last->obj;
		sphere->sphere_p = addition(sphere->sphere_p, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 9)
	{
		tri = (t_triangle *)(*ptr)->ptr_last->obj;
		tri->tr_p1 = addition(tri->tr_p1, tr);
		tri->tr_p2 = addition(tri->tr_p2, tr);
		tri->tr_p3 = addition(tri->tr_p3, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	trans_pl_cam(t_vector tr, t_cam_elm **c_ptr, t_element **ptr)
{
	t_plan *plan;
	t_camera *cam;
	if ((*ptr)->ptr_last->id == 5)
	{
		plan = (t_plan *)(*ptr)->ptr_last->obj;
		plan->plan_p = addition(plan->plan_p, tr);
		(*c_ptr)->c_ptr_last = NULL;
	}
	else if ((*c_ptr)->c_ptr_last != NULL)
	{
		cam = (t_camera *)(*c_ptr)->c_ptr_last->cam;
		cam->lookfrom = addition(cam->lookfrom, tr);
	}
}

void	translate(char **str, t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if (str[0][0] == 't' && str[0][1] == 'a')
	{
		if ((*ptr)->ptr_last)
		{
			trans_cy_sq_li(fill_translation(str), c_ptr, ptr);
			trans_sp_tr(fill_translation(str), c_ptr, ptr);
			trans_pl_cam(fill_translation(str), c_ptr, ptr);
		}
		else
			my_file(-300, 0);
	}
}
