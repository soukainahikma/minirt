/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:48:57 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 08:51:42 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_camera	*fill_camera(char **t)
{
	char		**t1;
	char		**t2;
	t_camera	*cam;

	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[2], ',');
	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->lookfrom.x = atof(t1[0]);
	cam->lookfrom.y = atof(t1[1]);
	cam->lookfrom.z = atof(t1[2]);
	cam->cam_d.x = atof(t2[0]);
	cam->cam_d.y = atof(t2[1]);
	cam->cam_d.z = atof(t2[2]);
	cam->fov = atof(t[3]);
	return (cam);
}
