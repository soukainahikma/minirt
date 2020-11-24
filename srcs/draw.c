/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:17:57 by shikma            #+#    #+#             */
/*   Updated: 2020/11/24 16:49:44 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		draw(t_vector ray, t_move *mv)
{
	t_element	*ptr;
	t_raydata	ray_info;
	double		t1;
	t_vector	color;

	ray_info.max_d[0] = INT_MAX;
	ray_info.max_d[1] = INT_MAX;
	ray_info.ray_direc[0] = ray;
	ptr = mv->liste;
	color = (t_vector){0, 0, 0};
	while (ptr != NULL)
	{
		ray_info.id = 0;
		t1 = inter(ptr, &ray_info, mv->object.camera->lookfrom, &mv->object);
		int t2 = 0;
		if (t1 == 1)
		{
			
			color = light(mv->liste, &mv->object, mv->data, ray_info);
			color = shadow(ptr, mv, color, ray_info,&t2);
		}
		ptr = ptr->next;
	}
	return (color);
}

void			image(t_move *move)
{
	double		i;
	double		j;
	int			k;
	t_vector	ray;

	i = 0;
	j = move->data.res->h - 1;
	k = 0;
	while (j-- >= 0)
	{
		i = 0;
		while (i++ < move->data.res->w)
		{
			ray = get_ray(move->object.camera,
			i / (move->data.res->w - 1), j / (move->data.res->h - 1));
			move->w.img_data[k++] = get_color(draw(ray, move));
		}
	}
}
