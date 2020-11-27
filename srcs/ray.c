/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:45:04 by shikma            #+#    #+#             */
/*   Updated: 2020/11/27 11:08:09 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		escape(int key, t_move *move)
{
	if (key == 53 || key == 12)
	{
		free_my_list(move->c_liste, move->liste);
		exit(0);
	}
}

t_vector	ray(t_vector origin, t_vector direction, double t)
{
	t_vector	a;
	t_vector	b;

	a = origin;
	b = direction;
	b = multiplication(t, b);
	a = addition(a, b);
	return (a);
}
