/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:07:28 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:45:16 by shikma           ###   ########.fr       */
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
	if (key == 124 && move->c_liste->next != NULL)
	{
		move->c_liste = move->c_liste->next;
		move->object.camera = move->c_liste->cam;
		ft_camera(move->object.camera, (t_vector){0, 1, 0},
		move->data.res.w / move->data.res.h);
		mlx_clear_window(move->w.mlx_ptr, move->w.win_ptr);
		image(move);
		mlx_put_image_to_window(move->w.mlx_ptr, move->w.win_ptr,
		move->w.img_ptr, 0, 0);
	}
	if (key == 123 && move->c_liste->prev != NULL)
	{
		move->c_liste = move->c_liste->prev;
		move->object.camera = move->c_liste->cam;
		ft_camera(move->object.camera, (t_vector){0, 1, 0},
		move->data.res.w / move->data.res.h);
		mlx_clear_window(move->w.mlx_ptr, move->w.win_ptr);
		image(move);
		mlx_put_image_to_window(move->w.mlx_ptr, move->w.win_ptr,
		move->w.img_ptr, 0, 0);
	}
	return (0);
}
