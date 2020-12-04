/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:48:57 by shikma            #+#    #+#             */
/*   Updated: 2020/12/04 14:07:59 by shikma           ###   ########.fr       */
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
	cam->lookfrom.x = ft_atof(t1[0]);
	cam->lookfrom.y = ft_atof(t1[1]);
	cam->lookfrom.z = ft_atof(t1[2]);
	cam->cam_d.x = ft_atof(t2[0]);
	cam->cam_d.y = ft_atof(t2[1]);
	cam->cam_d.z = ft_atof(t2[2]);
	cam->fov = ft_atof(t[3]);
	cam->cam_d.x += 0.0001;
	free_tab(t1, 3);
	free_tab(t2, 3);
	return (cam);
}
