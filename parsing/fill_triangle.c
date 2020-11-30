/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:17:40 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:13:17 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triangle	*fill_triangle(char **t)
{
	char		**t1;
	char		**t2;
	char		**t3;
	char		**t4;
	t_triangle	*tr;

	tr = (t_triangle *)malloc(sizeof(t_triangle));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[2], ',');
	t3 = ft_split(t[3], ',');
	t4 = ft_split(t[4], ',');
	tr->tr_p1.x = ft_atof(t1[0]);
	tr->tr_p1.y = ft_atof(t1[1]);
	tr->tr_p1.z = ft_atof(t1[2]);
	tr->tr_p2.x = ft_atof(t2[0]);
	tr->tr_p2.y = ft_atof(t2[1]);
	tr->tr_p2.z = ft_atof(t2[2]);
	tr->tr_p3.x = ft_atof(t3[0]);
	tr->tr_p3.y = ft_atof(t3[1]);
	tr->tr_p3.z = ft_atof(t3[2]);
	tr->tr_col.x = ft_atof(t4[0]);
	tr->tr_col.y = ft_atof(t4[1]);
	tr->tr_col.z = ft_atof(t4[2]);
	free_tab(t1,3);
	free_tab(t2,3);
	free_tab(t3,3);
	free_tab(t4,3);
	return (tr);
}
