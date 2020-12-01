/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:46:52 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:28:35 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_ambiant	fill_ambiant(char **t)
{
	char		**t1;
	t_ambiant	am;

	t1 = ft_split(t[2], ',');
	am.amb_p.x = ft_atof(t1[0]);
	am.amb_p.y = ft_atof(t1[1]);
	am.amb_p.z = ft_atof(t1[2]);
	am.ka = ft_atof(t[1]);
	free_tab(t1, 3);
	return (am);
}
