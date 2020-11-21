/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:59:25 by shikma            #+#    #+#             */
/*   Updated: 2020/11/21 12:00:35 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	light_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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

int	cy_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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

int	pl_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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
