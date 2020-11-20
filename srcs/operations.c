/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:26:07 by shikma            #+#    #+#             */
/*   Updated: 2020/11/13 13:27:56 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	addition(t_vector a, t_vector b)
{
	t_vector	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	return (add);
}

t_vector	soustraction(t_vector a, t_vector b)
{
	t_vector	add;

	add.x = a.x - b.x;
	add.y = a.y - b.y;
	add.z = a.z - b.z;
	return (add);
}

t_vector	multiplication(double a, t_vector b)
{
	t_vector	add;

	add.x = a * b.x;
	add.y = a * b.y;
	add.z = a * b.z;
	return (add);
}

t_vector	division(double a, t_vector b)
{
	t_vector	add;

	add.x = b.x / a;
	add.y = b.y / a;
	add.z = b.z / a;
	return (add);
}
