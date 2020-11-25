/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:21:00 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 19:36:32 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rot_cy_sq(t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if ((*ptr)->ptr_last->id == 8)
	{
		obj->cy = (t_cylindre *)(*ptr)->ptr_last->obj;
		obj->cy->cy_d = rot_x(obj->cy->cy_d, obj->rot->x * M_PI / 180);
		obj->cy->cy_d = rot_y(obj->cy->cy_d, obj->rot->y * M_PI / 180);
		obj->cy->cy_d = rot_z(obj->cy->cy_d, obj->rot->z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last->id == 7)
	{
		obj->sq = (t_sq *)(*ptr)->ptr_last->obj;
		obj->sq->sq_d = rot_x(obj->sq->sq_d, obj->rot->x * M_PI / 180);
		obj->sq->sq_d = rot_y(obj->sq->sq_d, obj->rot->y * M_PI / 180);
		obj->sq->sq_d = rot_z(obj->sq->sq_d, obj->rot->z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	rot_pl_cam(t_object *o, t_cam_elm **c_ptr, t_element **ptr)
{
	if ((*ptr)->ptr_last->id == 5)
	{
		o->plan = (t_plan *)(*ptr)->ptr_last->obj;
		o->plan->plan_d = rot_x(o->plan->plan_d, o->rot->x * M_PI / 180);
		o->plan->plan_d = rot_y(o->plan->plan_d, o->rot->y * M_PI / 180);
		o->plan->plan_d = rot_z(o->plan->plan_d, o->rot->z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
	else if ((*c_ptr)->c_ptr_last != NULL)
	{
		o->camera = (t_camera *)(*c_ptr)->c_ptr_last->cam;
		o->camera->cam_d = rot_x(o->camera->cam_d, o->rot->x * M_PI / 180);
		o->camera->cam_d = rot_y(o->camera->cam_d, o->rot->y * M_PI / 180);
		o->camera->cam_d = rot_z(o->camera->cam_d, o->rot->z * M_PI / 180);
	}
}

void	rotate(char **info, t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if (info[0][0] == 'r' && info[0][1] == 'o')
	{
		if ((*ptr)->ptr_last)
		{
			obj->rot = fill_rotation(info);
			rot_cy_sq(obj, c_ptr, ptr);
			rot_pl_cam(obj, c_ptr, ptr);
		}
		else
			my_file(-300, 0);
	}
}
