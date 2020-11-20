/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:51 by shikma            #+#    #+#             */
/*   Updated: 2020/11/19 12:07:13 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"
void	fill_cam(char **info, t_data *data, t_object *object, t_cam_elm **c_ptr)
{
	t_cam_elm *p;

	if (info[0][0] == 'c' && info[0][1] != 'y')
	{
		object->camera = fill_camera(info);
		if (*c_ptr == NULL)
			*c_ptr = create_c_list(object->camera, sizeof(t_camera));
		else
			*c_ptr = add_c_end(c_ptr, object->camera, sizeof(t_camera));
	}
}
void	rotate(char **info, t_object *object, t_cam_elm **c_ptr,t_element **ptr)
{
	
	 if(info[0][0] == 'r' && info[0][1] == 'o' && info[0][2] == 't')
    	{
        object->rot = fill_rotation(info);
		if((*ptr)->ptr_last->id == 8)
    	{
    		object->cy =(t_cylindre *) (*ptr)->ptr_last->obj;
			object->cy->cy_d = rot_x(object->cy->cy_d,object->rot->x * M_PI / 180);
			object->cy->cy_d = rot_y(object->cy->cy_d,object->rot->y * M_PI / 180);
			object->cy->cy_d = rot_z(object->cy->cy_d,object->rot->z * M_PI / 180);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 7)
    	{
    		object->sq =(t_sq *) (*ptr)->ptr_last->obj;
			object->sq->sq_d = rot_x(object->sq->sq_d,object->rot->x * M_PI / 180);
			object->sq->sq_d = rot_y(object->sq->sq_d,object->rot->y * M_PI / 180);
			object->sq->sq_d = rot_z(object->sq->sq_d,object->rot->z * M_PI / 180);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 5)
    	{
    		object->plan =(t_plan *) (*ptr)->ptr_last->obj;
			object->plan->plan_d = rot_x(object->plan->plan_d,object->rot->x * M_PI / 180);
			object->plan->plan_d = rot_y(object->plan->plan_d,object->rot->y * M_PI / 180);
			object->plan->plan_d = rot_z(object->plan->plan_d,object->rot->z * M_PI / 180);
			(*c_ptr)->c_ptr_last = NULL;
		}
		else if((*c_ptr)->c_ptr_last != NULL)
    	{
    		object->camera =(t_camera *) (*c_ptr)->c_ptr_last->cam;
			object->camera->cam_d = rot_x(object->camera->cam_d,object->rot->x * M_PI / 180);
			object->camera->cam_d = rot_y(object->camera->cam_d,object->rot->y * M_PI / 180);
			object->camera->cam_d = rot_z(object->camera->cam_d,object->rot->z * M_PI / 180);
			printf("%f,%f,%f\n",object->camera->cam_d.x,object->camera->cam_d.x,object->camera->cam_d.z);
		}	
	}
}
void	translate(char **info, t_object *object, t_cam_elm **c_ptr,t_element **ptr)
{
	if(info[0][0] == 't' && info[0][1] == 'r' && info[0][2] == 'a')
    	{
			
        object->tr = fill_translation(info);
		if((*ptr)->ptr_last->id == 8)
    	{
    		object->cy =(t_cylindre *) (*ptr)->ptr_last->obj;
			object->cy->cy_p = addition(object->cy->cy_p, *object->tr);
			
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 7)
    	{
    		object->sq =(t_sq *) (*ptr)->ptr_last->obj;
			object->sq->sq_p = addition(object->sq->sq_p, *object->tr);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 4)
		{
			object->light_n =(t_light *) (*ptr)->ptr_last->obj;
			object->light_n->light_p = addition(object->light_n->light_p, *object->tr);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 6)
		{
			object->sphere =(t_sphere *) (*ptr)->ptr_last->obj;
			object->sphere->sphere_p = addition(object->sphere->sphere_p, *object->tr);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 9)
		{
			object->triangle =(t_triangle *) (*ptr)->ptr_last->obj;
			object->triangle->tr_p1 = addition(object->triangle->tr_p1, *object->tr);
			object->triangle->tr_p2 = addition(object->triangle->tr_p2, *object->tr);
			object->triangle->tr_p3 = addition(object->triangle->tr_p3, *object->tr);
			(*c_ptr)->c_ptr_last = NULL;
		}
		if((*ptr)->ptr_last->id == 5)
    	{
    		object->plan =(t_plan *) (*ptr)->ptr_last->obj;
			object->plan->plan_p = addition(object->plan->plan_p, *object->tr);
			(*c_ptr)->c_ptr_last = NULL;
		}
		else if((*c_ptr)->c_ptr_last != NULL)
    	{
    		object->camera =(t_camera *) (*c_ptr)->c_ptr_last->cam;
			object->camera->lookfrom = addition(object->camera->lookfrom, *object->tr);
			
		}	
	}
}

void	parsing(t_move *move, t_element **ptr, t_cam_elm **c_ptr,char *str)
{
	char	*line;
	int		fd;
	char	**t;
	int		rest;

	fd = open(str, O_RDONLY);
	rest = 1;
	while (rest == 1)
	{
		rest = get_next_line(fd, &line);
		if (line[0] == '\0')
			continue;
		t = ft_split_whitespaces(line);
		fill_struct(t, &move->data, &move->object, ptr);
		fill_cam(t, &move->data, &move->object, c_ptr);
		rotate(t, &move->object, c_ptr, ptr);
		translate(t, &move->object, c_ptr, ptr);
	}
	close(fd);
}
