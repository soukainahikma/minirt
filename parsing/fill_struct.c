/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:29:13 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 17:33:47 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	struct_1(char **info, t_data *data)
{
	if (info[0][0] == 'R')
	{
		data->res = fill_resolution(info);
		free_tab(info, 3);
	}
	else if (info[0][0] == 'A')
	{
		data->am = fill_ambiant(info);
		free_tab(info, 3);
	}
}

void	struct_4(char **info, t_element **liste)
{
	if (info[0][0] == 'c' && info[0][1] == 'y')
	{
		if (*liste == NULL)
			*liste = create_list(fill_cylindre(info), 8, sizeof(t_cylindre));
		else
			*liste = add_end(liste, fill_cylindre(info), 8, sizeof(t_cylindre));
		free_tab(info, 6);
	}
}

void	struct_2(char **info, t_element **liste)
{
	if (info[0][0] == 'l')
	{
		if (*liste == NULL)
			*liste = create_list(fill_light(info), 4, sizeof(t_light));
		else
			*liste = add_end(liste, fill_light(info), 4, sizeof(t_light));
		free_tab(info, 4);
	}
	else if (info[0][0] == 'p' && info[0][1] == 'l')
	{
		if (*liste == NULL)
			*liste = create_list(fill_plan(info), 5, sizeof(t_plan));
		else
			*liste = add_end(liste, fill_plan(info), 5, sizeof(t_plan));
		free_tab(info, 4);
	}
	else if (info[0][0] == 's' && info[0][1] == 'p')
	{
		if (*liste == NULL)
			*liste = create_list(fill_sphere(info), 6, sizeof(t_sphere));
		else
			*liste = add_end(liste, fill_sphere(info), 6, sizeof(t_sphere));
		free_tab(info, 4);
	}
}

void	struct_3(char **info, t_element **liste)
{
	if (info[0][0] == 's' && info[0][1] == 'q')
	{
		if (*liste == NULL)
			*liste = create_list(fill_square(info), 7, sizeof(t_sq));
		else
			*liste = add_end(liste, fill_square(info), 7, sizeof(t_sq));
		free_tab(info, 5);
	}
	else if (info[0][0] == 't' && info[0][1] == 'r')
	{
		if (*liste == NULL)
			*liste = create_list(fill_triangle(info), 9, sizeof(t_triangle));
		else
			*liste = add_end(liste, fill_triangle(info), 9, sizeof(t_triangle));
		free_tab(info, 5);
	}
}

void	fill_struct(char **info, t_data *data, t_element **liste)
{
	struct_1(info, data);
	struct_2(info, liste);
	struct_4(info, liste);
	struct_3(info, liste);
}
