/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:29:13 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 19:36:17 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	struct_1(char **info, t_data *data, t_object *obj, t_element **liste)
{
	if (info[0][0] == 'R')
	{
		data->res = fill_resolution(info);
		if (*liste == NULL)
			*liste = create_list(data->res, 1, sizeof(t_resolution));
		else
			*liste = add_end(liste, data->res, 1, sizeof(t_resolution));
		(*liste)->ptr_last = NULL;
	}
	else if (info[0][0] == 'A')
	{
		data->am = fill_ambiant(info);
		if (*liste == NULL)
			*liste = create_list(data->am, 2, sizeof(t_ambiant));
		else
			*liste = add_end(liste, data->am, 2, sizeof(t_ambiant));
		(*liste)->ptr_last = NULL;
	}
}

void	struct_4(char **info, t_data *data, t_object *obj, t_element **liste)
{
	if (info[0][0] == 'c' && info[0][1] == 'y')
	{
		obj->cy = fill_cylindre(info);
		if (*liste == NULL)
			*liste = create_list(obj->cy, 8, sizeof(t_cylindre));
		else
			*liste = add_end(liste, obj->cy, 8, sizeof(t_cylindre));
	}
}

void	struct_2(char **info, t_data *data, t_object *obj, t_element **liste)
{
	if (info[0][0] == 'l')
	{
		obj->light = fill_light(info);
		if (*liste == NULL)
			*liste = create_list(obj->light, 4, sizeof(t_light));
		else
			*liste = add_end(liste, obj->light, 4, sizeof(t_light));
	}
	else if (info[0][0] == 'p' && info[0][1] == 'l')
	{
		obj->plan = fill_plan(info);
		if (*liste == NULL)
			*liste = create_list(obj->plan, 5, sizeof(t_plan));
		else
			*liste = add_end(liste, obj->plan, 5, sizeof(t_plan));
	}
	else if (info[0][0] == 's' && info[0][1] == 'p')
	{
		obj->sphere = fill_sphere(info);
		if (*liste == NULL)
			*liste = create_list(obj->sphere, 6, sizeof(t_sphere));
		else
			*liste = add_end(liste, obj->sphere, 6, sizeof(t_sphere));
	}
}

void	struct_3(char **info, t_data *data, t_object *obj, t_element **liste)
{
	if (info[0][0] == 's' && info[0][1] == 'q')
	{
		obj->sq = fill_square(info);
		if (*liste == NULL)
			*liste = create_list(obj->sq, 7, sizeof(t_sq));
		else
			*liste = add_end(liste, obj->sq, 7, sizeof(t_sq));
	}
	else if (info[0][0] == 't' && info[0][1] == 'r' && info[0][2] != 'a')
	{
		obj->triangle = fill_triangle(info);
		if (*liste == NULL)
			*liste = create_list(obj->triangle, 9, sizeof(t_triangle));
		else
			*liste = add_end(liste, obj->triangle, 9, sizeof(t_triangle));
	}
}

void	fill_struct(char **info, t_data *data, t_object *obj, t_element **liste)
{
	struct_1(info, data, obj, liste);
	struct_2(info, data, obj, liste);
	struct_4(info, data, obj, liste);
	struct_3(info, data, obj, liste);
}
