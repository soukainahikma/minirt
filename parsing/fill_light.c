/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:02:11 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:29:17 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*fill_light(char **t)
{
	char		**t1;
	char		**t2;
	t_light		*l;

	l = (t_light *)malloc(sizeof(t_light));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[3], ',');
	l->light_p.x = ft_atof(t1[0]);
	l->light_p.y = ft_atof(t1[1]);
	l->light_p.z = ft_atof(t1[2]);
	l->kl = ft_atof(t[2]);
	l->color.x = ft_atof(t2[0]);
	l->color.y = ft_atof(t2[1]);
	l->color.z = ft_atof(t2[2]);
	free_tab(t1, 3);
	free_tab(t2, 3);
	return (l);
}
