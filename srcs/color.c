/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:40:30 by shikma            #+#    #+#             */
/*   Updated: 2020/11/13 13:43:06 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	c(double value, double min, double max)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}

int		get_color(t_vector clr)
{
	unsigned char	color[4];

	color[0] = c(clr.z * 255, 0, 255);
	color[1] = c(clr.y * 255, 0, 255);
	color[2] = c(clr.x * 255, 0, 255);
	color[3] = 0;
	return (*((int *)color));
}
