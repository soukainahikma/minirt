/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:15:24 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:10:47 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylindre	*fill_cylindre(char **t)
{
	char		**t1;
	char		**t2;
	char		**t3;
	t_cylindre	*cy;

	cy = (t_cylindre *)malloc(sizeof(t_cylindre));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[2], ',');
	t3 = ft_split(t[3], ',');
	cy->cy_p.x = ft_atof(t1[0]);
	cy->cy_p.y = ft_atof(t1[1]);
	cy->cy_p.z = ft_atof(t1[2]);
	cy->cy_d.x = ft_atof(t2[0]);
	cy->cy_d.y = ft_atof(t2[1]);
	cy->cy_d.z = ft_atof(t2[2]);
	cy->diam = ft_atof(t[4]);
	cy->h = ft_atof(t[5]);
	cy->cy_col.x = ft_atof(t3[0]);
	cy->cy_col.y = ft_atof(t3[1]);
	cy->cy_col.z = ft_atof(t3[2]);
	free_tab(t1,3);
	free_tab(t2,3);
	free_tab(t3,3);
	return (cy);
}
