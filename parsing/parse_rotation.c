/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:21:00 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 12:28:22 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rot_cy_sq(t_vector rot, t_cam_elm **c_ptr, t_element **ptr)
{
	t_sq *sq;
	t_cylindre *cy;

	if ((*ptr)->ptr_last && (*ptr)->ptr_last->id == 8)
	{
		cy = (t_cylindre *)(*ptr)->ptr_last->obj;
		cy->cy_d = rot_x(cy->cy_d, rot.x * M_PI / 180);
		cy->cy_d = rot_y(cy->cy_d, rot.y * M_PI / 180);
		cy->cy_d = rot_z(cy->cy_d, rot.z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
	if ((*ptr)->ptr_last && (*ptr)->ptr_last->id == 7)
	{
		sq = (t_sq *)(*ptr)->ptr_last->obj;
		sq->sq_d = rot_x(sq->sq_d, rot.x * M_PI / 180);
		sq->sq_d = rot_y(sq->sq_d, rot.y * M_PI / 180);
		sq->sq_d = rot_z(sq->sq_d, rot.z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
}

void	rot_pl_cam(t_vector rot, t_cam_elm **c_ptr, t_element **ptr)
{
	t_plan *p;
	t_camera *c;

	if ((*ptr)->ptr_last && (*ptr)->ptr_last->id == 5)
	{
		p = (t_plan *)(*ptr)->ptr_last->obj;
		p->plan_d = rot_x(p->plan_d, rot.x * M_PI / 180);
		p->plan_d = rot_y(p->plan_d, rot.y * M_PI / 180);
		p->plan_d = rot_z(p->plan_d, rot.z * M_PI / 180);
		(*c_ptr)->c_ptr_last = NULL;
	}
	else if ((*c_ptr)->c_ptr_last != NULL)
	{
		c = (t_camera *)(*c_ptr)->c_ptr_last->cam;
		c->cam_d = rot_x(c->cam_d, rot.x * M_PI / 180);
		c->cam_d = rot_y(c->cam_d, rot.y * M_PI / 180);
		c->cam_d = rot_z(c->cam_d, rot.z * M_PI / 180);
	}
}

void	rotate(char **info, t_object *obj, t_cam_elm **c_ptr, t_element **ptr)
{
	if (info[0][0] == 'r' && info[0][1] == 'o')
	{
		if ((*ptr)->ptr_last != NULL || (*c_ptr)->c_ptr_last != NULL)
		{
		//	obj->rot = fill_rotation(info);
			rot_cy_sq(fill_rotation(info), c_ptr, ptr);
			rot_pl_cam(fill_rotation(info), c_ptr, ptr);
		}
		else
			my_file(-300, 0);
	}
}
