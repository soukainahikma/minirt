/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:46:52 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 07:33:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_ambiant	*fill_ambiant(char **t)
{
	char		**t1;
	t_ambiant	*am;

	t1 = ft_split(t[2], ',');
	am = (t_ambiant *)malloc(sizeof(t_ambiant));
	am->amb_p.x = ft_atof(t1[0]);
	am->amb_p.y = ft_atof(t1[1]);
	am->amb_p.z = ft_atof(t1[2]);
	am->ka = ft_atof(t[1]);
	return (am);
}
