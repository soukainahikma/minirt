/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:58:49 by shikma            #+#    #+#             */
/*   Updated: 2020/11/21 12:00:31 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	sp_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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

int	sq_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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

int	tr_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
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

int	tra_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
	if (nb_word(str) != 2)
		return (11);
	if (check_position(info[1]) == 0)
		return (-10);
	return (0);
}

int	rot_checker(char *str)
{
	char **info;

	info = ft_split_whitespaces(str);
	if (nb_word(str) != 2)
		return (12);
	if (check_position(info[1]) == 0)
		return (-11);
	return (0);
}
