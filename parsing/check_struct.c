/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:54:13 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 14:22:10 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_struct(char *str, int *error_nb)
{
	char **info;

	if (nb_word(str) == 0)
		return (-2);
	info = ft_split_whitespaces(str);
	if (info[0][0] == 'R' && ft_strlen(info[0]) == 1)
	{
		if (nb_word(str) != 3)
			return (2);
		if (check_kl_ka_fov_res(3, info[1]) == 0)
			return (21);
		if (check_kl_ka_fov_res(3, info[2]) == 0)
			return (22);
		error_nb[0]++;
		if (error_nb[0] > 1)
			return (-6);
		return (0);
	}
	else if (info[0][0] == 'A' && ft_strlen(info[0]) == 1)
	{
		if (nb_word(str) != 3)
			return (3);
		if (check_kl_ka_fov_res(1, info[1]) == 0)
			return (31);
		if (check_color(info[2]) == 0)
			return (32);
		error_nb[1]++;
		if (error_nb[1] > 1)
			return (-7);
		return (0);
	}
	else if (info[0][0] == 'c' && ft_strlen(info[0]) == 1)
	{
		if (nb_word(str) != 4)
			return (4);
		if (check_position(info[1]) == 0)
			return (41);
		if (check_normal(info[2]) == 0)
			return (42);
		if (check_kl_ka_fov_res(2, info[3]) == 0)
			return (43);
		error_nb[2]++;
		return (0);
	}
	else if (info[0][0] == 'l' && ft_strlen(info[0]) == 1)
	{
		if (nb_word(str) != 4)
			return (5);
		if (check_position(info[1]) == 0)
			return (51);
		if (check_kl_ka_fov_res(1, info[2]) == 0)
			return (52);
		if (check_color(info[3]) == 0)
			return (53);
		return (0);
	}
	else if (info[0][0] == 'c' && info[0][1] == 'y' && ft_strlen(info[0]) == 2)
	{
		if (nb_word(str) != 6)
			return (6);
		if (check_position(info[1]) == 0)
			return (61);
		if (check_normal(info[2]) == 0)
			return (62);
		if (check_color(info[3]) == 0)
			return (63);
		if (check_size(info[4]) == 0)
			return (64);
		if (check_size(info[5]) == 0)
			return (65);
		return (0);
	}
	else if (info[0][0] == 'p' && info[0][1] == 'l' && ft_strlen(info[0]) == 2)
	{
		if (nb_word(str) != 4)
			return (7);
		if (check_position(info[1]) == 0)
			return (71);
		if (check_normal(info[2]) == 0)
			return (72);
		if (check_color(info[3]) == 0)
			return (73);
		return (0);
	}
	else if (info[0][0] == 's' && info[0][1] == 'p' && ft_strlen(info[0]) == 2)
	{
		if (nb_word(str) != 4)
			return (8);
		if (check_position(info[1]) == 0)
			return (81);
		if (check_size(info[2]) == 0)
			return (82);
		if (check_color(info[3]) == 0)
			return (83);
		return (0);
	}
	else if (info[0][0] == 's' && info[0][1] == 'q' && ft_strlen(info[0]) == 2)
	{
		if (nb_word(str) != 5)
			return (9);
		if (check_position(info[1]) == 0)
			return (91);
		if (check_normal(info[2]) == 0)
			return (92);
		if (check_size(info[3]) == 0)
			return (93);
		if (check_color(info[4]) == 0)
			return (94);
		return (0);
	}
	else if (info[0][0] == 't' && info[0][1] == 'r' && ft_strlen(info[0]) == 2)
	{
		if (nb_word(str) != 5)
			return (10);
		if (check_position(info[1]) == 0)
			return (101);
		if (check_position(info[2]) == 0)
			return (102);
		if (check_position(info[3]) == 0)
			return (103);
		if (check_color(info[4]) == 0)
			return (104);
		return (0);
	}
	else if (info[0][0] == 't' && info[0][1] == 'r' &&
		info[0][2] == 'a' && ft_strlen(info[0]) == 3)
	{
		if (nb_word(str) != 2)
			return (11);
		if (check_position(info[1]) == 0)
			return (-10);
		return (0);
	}
	else if (info[0][0] == 'r' && info[0][1] == 'o' &&
		info[0][2] == 't' && ft_strlen(info[0]) == 3)
	{
		if (nb_word(str) != 2)
			return (12);
		if (check_position(info[1]) == 0)
			return (-11);
		return (0);
	}
	return (-1);
}
