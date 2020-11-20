/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:46:52 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 08:46:53 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_ambiant	*fill_ambiant(char **t)
{
	char		**t1;
	t_ambiant	*am;

	t1 = ft_split(t[2], ',');
	am = (t_ambiant *)malloc(sizeof(t_ambiant));
	am->amb_p.x = atof(t1[0]);
	am->amb_p.y = atof(t1[1]);
	am->amb_p.z = atof(t1[2]);
	am->ka = atof(t[1]);
	return (am);
}
