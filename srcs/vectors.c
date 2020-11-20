/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:20:25 by shikma            #+#    #+#             */
/*   Updated: 2020/11/13 13:26:28 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		dot(t_vector a, t_vector b)
{
	double result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

double		norm(t_vector a)
{
	double	n;

	n = a.x * a.x + a.y * a.y + a.z * a.z;
	n = sqrt(n);
	return (n);
}

t_vector	get_normalize(t_vector a)
{
	double		norm_;
	t_vector	n;

	norm_ = norm(a);
	n.x = a.x / norm_;
	n.y = a.y / norm_;
	n.z = a.z / norm_;
	return (n);
}

t_vector	cross(t_vector a, t_vector b)
{
	t_vector cross_product;

	cross_product.x = a.y * b.z - a.y * b.y;
	cross_product.y = a.z * b.x - a.x * b.z;
	cross_product.z = a.x * b.y - a.y * b.x;
	return (cross_product);
}
