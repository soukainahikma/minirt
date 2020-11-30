/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:13:55 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:12:29 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*fill_sphere(char **t)
{
	char		**t1;
	char		**t2;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[3], ',');
	sphere->sphere_p.x = ft_atof(t1[0]);
	sphere->sphere_p.y = ft_atof(t1[1]);
	sphere->sphere_p.z = ft_atof(t1[2]);
	sphere->diametre = ft_atof(t[2]);
	sphere->sphere_col.x = ft_atof(t2[0]);
	sphere->sphere_col.y = ft_atof(t2[1]);
	sphere->sphere_col.z = ft_atof(t2[2]);
	free_tab(t1,3);
	free_tab(t2,3);
	return (sphere);
}
