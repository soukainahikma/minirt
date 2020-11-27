/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:59:29 by shikma            #+#    #+#             */
/*   Updated: 2020/11/26 21:42:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	res_checker(char *str, int **error_nb)
{
	char **info;

	info = ft_split_whitespaces(str);
	if (nb_word(str) != 3)
		return (2);
	if (check_kl_ka_fov_res(3, info[1]) == 0)
		return (21);
	if (check_kl_ka_fov_res(3, info[2]) == 0)
		return (22);
	(*error_nb)[0]++;
	if ((*error_nb)[0] > 1)
		return (-6);
	return (0);
}

int	am_checker(char *str, int **error_nb)
{
	char **info;

	info = ft_split_whitespaces(str);
	if (nb_word(str) != 3)
		return (3);
	if (check_kl_ka_fov_res(1, info[1]) == 0)
		return (31);
	if (check_color(info[2]) == 0)
		return (32);
	(*error_nb)[1]++;
	if ((*error_nb)[1] > 1)
		return (-7);
	return (0);
}

int	cam_checker(char *str, int **error_nb)
{
	char **info;

	info = ft_split_whitespaces(str);
	if (nb_word(str) != 4)
		return (4);
	if (check_position(info[1]) == 0)
		return (41);
	if (check_normal(info[2]) == 0)
		return (42);
	if (check_kl_ka_fov_res(2, info[3]) == 0)
		return (43);
	(*error_nb)[2]++;
	return (0);
}

int	just_checking(char *str,int *er, int error)
{
	if (er[0] == 0)
		return (my_checker_free(str, -8, 0));
	if (er[1] == 0)
		return (my_checker_free(str, -13, 0));
	if (er[2] == 0)
		return (my_checker_free(str, -9, 0));
	return (error);
}
