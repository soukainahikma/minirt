/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 08:52:52 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 16:29:11 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_sq	*fill_square(char **t)
{
	char	**t1;
	char	**t2;
	char	**t3;
	t_sq	*sq;

	sq = (t_sq *)malloc(sizeof(t_sq));
	t1 = ft_split(t[1], ',');
	t2 = ft_split(t[2], ',');
	t3 = ft_split(t[4], ',');
	sq->sq_p.x = ft_atof(t1[0]);
	sq->sq_p.y = ft_atof(t1[1]);
	sq->sq_p.z = ft_atof(t1[2]);
	sq->sq_d.x = ft_atof(t2[0]);
	sq->sq_d.y = ft_atof(t2[1]);
	sq->sq_d.z = ft_atof(t2[2]);
	sq->side_size = ft_atof(t[3]);
	sq->sq_col.x = ft_atof(t3[0]);
	sq->sq_col.y = ft_atof(t3[1]);
	sq->sq_col.z = ft_atof(t3[2]);
	free_tab(t1, 3);
	free_tab(t2, 3);
	free_tab(t3, 3);
	return (sq);
}
