/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:07:28 by shikma            #+#    #+#             */
/*   Updated: 2020/11/21 18:25:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	rot_x(t_vector vec, double teta)
{
	double tmp;

	tmp = vec.y;
	vec.y = (vec.y * cos(teta)) - (vec.z * sin(teta));
	vec.z = tmp * sin(teta) + (vec.z * cos(teta));
	return (vec);
}

t_vector	rot_y(t_vector vec, double teta)
{
	double tmp;

	tmp = vec.z;
	vec.z = (vec.z * cos(teta)) - (vec.x * sin(teta));
	vec.x = tmp * sin(teta) + (vec.x * cos(teta));
	return (vec);
}

t_vector	rot_z(t_vector vec, double teta)
{
	double tmp;

	tmp = vec.x;
	vec.x = (vec.x * cos(teta)) - (vec.y * sin(teta));
	vec.y = tmp * sin(teta) + (vec.y * cos(teta));
	return (vec);
}

int			press_key(int key, t_move *move)
{
	if (key == 53 || key == 12)
		exit(0);
	if (key == 124 && move->button == 3 && move->c_liste->next != NULL)
	{
		move->c_liste = move->c_liste->next;
		move->object.camera = move->c_liste->cam;
		ft_camera(move->object.camera, (t_vector){0, 1, 0},
		move->data.res->w / move->data.res->h);
		mlx_clear_window(move->w.mlx_ptr, move->w.win_ptr);
		image(move);
		mlx_put_image_to_window(move->w.mlx_ptr, move->w.win_ptr,
		move->w.img_ptr, 0, 0);
	}
	if (key == 123 && move->button == 3 && move->c_liste->prev != NULL)
	{
		move->c_liste = move->c_liste->prev;
		move->object.camera = move->c_liste->cam;
		ft_camera(move->object.camera, (t_vector){0, 1, 0},
		move->data.res->w / move->data.res->h);
		mlx_clear_window(move->w.mlx_ptr, move->w.win_ptr);
		image(move);
		mlx_put_image_to_window(move->w.mlx_ptr, move->w.win_ptr,
		move->w.img_ptr, 0, 0);
	}
	return (0);
}

int			press_mouse(int button, int x, int y, t_move *move)
{
	t_raydata	ray_;
	t_element	*ptr;
	t_element	*object_info;
	double		t1;
	double		u[2];

	move->button = button;
	ray_.max_d[0] = INT_MAX;
	u[0] = (double)(x / move->data.res-> w);
	u[1] = (double)((move->data.res->h - y) / move->data.res->h);
	ray_.ray_direc[0] = get_ray(move->object.camera, u[0], u[1]);
	ptr = move->liste;
	while (ptr != NULL)
	{
		ray_.id = 0;
		t1 = inter(ptr, &ray_, move->object.camera->lookfrom, &move->object);
		if (t1 == 1)
			move->ptr = ptr;
		ptr = ptr->next;
	}
	return (0);
}
