/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c_and_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:15:22 by shikma            #+#    #+#             */
/*   Updated: 2020/12/04 13:59:08 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	get_camera_direction(t_camera cam, t_vector get_ray)
{
	t_vector ray;

	cam.low_left_c = addition(cam.low_left_c, get_ray);
	ray = soustraction(cam.low_left_c, cam.lookfrom);
	return (ray);
}

void		ft_camera(t_camera *cam, t_vector vup, double aspect)
{
	t_vector	i;
	t_vector	j;
	t_vector	k;
	double		half_h;
	double		half_w;

	half_h = tan((cam->fov * M_PI / 180) / 2);
	half_w = aspect * half_h;
	i = get_normalize(multiplication(-1, cam->cam_d));
	j = get_normalize(cross(vup, i));
	k = cross(i, j);
	cam->low_left_c.x = cam->lookfrom.x - half_w * j.x - half_h * k.x - i.x;
	cam->low_left_c.y = cam->lookfrom.y - half_w * j.y - half_h * k.y - i.y;
	cam->low_left_c.z = cam->lookfrom.z - half_w * j.z - half_h * k.z - i.z;
	cam->horizontal = multiplication(2 * half_w, j);
	cam->vertical = multiplication(2 * half_h, k);
}

t_vector	get_ray(t_camera *camera_, double u, double v)
{
	t_vector	get_direction;
	t_vector	horizontal_;
	t_vector	vertical_;

	horizontal_ = multiplication(u, camera_->horizontal);
	vertical_ = multiplication(v, camera_->vertical);
	get_direction = addition(horizontal_, vertical_);
	get_direction = get_camera_direction(*camera_, get_direction);
	return (get_direction);
}
