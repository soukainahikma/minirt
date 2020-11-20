/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:27:17 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 12:18:02 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_1(int error, char **str)
{
	if (error == -1)
		(*str) = "ERROR -1: wrong parsing \n";
	if (error == -2)
		(*str) = "ERROR -2: line with no information \n";
	if (error == -3)
		(*str) = "ERROR -3: No such file .rt\n";
	if (error == -4)
		(*str) = "ERROR -4: Wrong extention \n";
	if (error == -5)
		(*str) = "ERROR -5: Wrong number of argument \n";
	if (error == -6)
		(*str) = "ERROR -6: double resolution \n";
	if (error == -7)
		(*str) = "ERROR -7: double ambiant \n";
	if (error == -8)
		(*str) = "ERROR -8: No resolution \n";
	if (error == -9)
		(*str) = "ERROR -9: No camera \n";
	if (error == -10)
		(*str) = "ERROR -10: wrong translation coordinates \n";
	if (error == -11)
		(*str) = "ERROR -11: wrong rotation coordinates \n";
	if (error == -12)
		(*str) = "ERROR -12: Did you mean --save ?\n";
}

void	error_2(int error, char **str)
{
	if (error == 2)
		(*str) = "ERROR 2: incomplete resolution informations \n";
	if (error == 3)
		(*str) = "ERROR 3: incomplete ambiant informations \n";
	if (error == 4)
		(*str) = "ERROR 4: incomplete camera informations \n";
	if (error == 5)
		(*str) = "ERROR 5: incomplete light informations \n";
	if (error == 6)
		(*str) = "ERROR 6: incomplete cylinder informations \n";
	if (error == 7)
		(*str) = "ERROR 7: incomplete plan informations \n";
	if (error == 8)
		(*str) = "ERROR 8: incomplete sphere informations \n";
	if (error == 9)
		(*str) = "ERROR 9: incomplete sq informations \n";
	if (error == 10)
		(*str) = "ERROR 10: incomplete triangle informations \n";
	if (error == 11)
		(*str) = "ERROR 11: incomplete translaton informations \n";
	if (error == 12)
		(*str) = "ERROR 12: incomplete rotation informations \n";
	if (error == 21)
		(*str) = "ERROR 21: invalid width resolution \n";
}

void	error_3(int error, char **str)
{
	if (error == 22)
		(*str) = "ERROR 22: invalid height resolution \n";
	if (error == 31)
		(*str) = "ERROR 31: invalid anbiant intesity \n";
	if (error == 32)
		(*str) = "ERROR 32: invalid anbiant color \n";
	if (error == 41)
		(*str) = "ERROR 41: invalid camera position \n";
	if (error == 42)
		(*str) = "ERROR 42: invalid camera normal \n";
	if (error == 43)
		(*str) = "ERROR 43: invalid camera fov \n";
	if (error == 51)
		(*str) = "ERROR 51: invalid light position \n";
	if (error == 52)
		(*str) = "ERROR 52: invalid light intesity \n";
	if (error == 53)
		(*str) = "ERROR 53: invalid light color \n";
	if (error == 61)
		(*str) = "ERROR 61: invalid cylinder position \n";
	if (error == 62)
		(*str) = "ERROR 62: invalid cylinder normal \n";
	if (error == 63)
		(*str) = "ERROR 63: invalid cylinder color \n";
}

void	error_4(int error, char **str)
{
	if (error == 64)
		(*str) = "ERROR 64: invalid cylinder diameter \n";
	if (error == 65)
		(*str) = "ERROR 65: invalid cylinder height \n";
	if (error == 71)
		(*str) = "ERROR 71: invalid plan position \n";
	if (error == 72)
		(*str) = "ERROR 72: invalid plan normal \n";
	if (error == 73)
		(*str) = "ERROR 73: invalid plan color \n";
	if (error == 81)
		(*str) = "ERROR 81: invalid sphere position \n";
	if (error == 82)
		(*str) = "ERROR 82: invalid sphere diameter \n";
	if (error == 83)
		(*str) = "ERROR 83: invalid sphere color \n";
	if (error == 91)
		(*str) = "ERROR 91: invalid sq position \n";
	if (error == 92)
		(*str) = "ERROR 92: invalid sq normal \n";
	if (error == 93)
		(*str) = "ERROR 93: invalid sq size side \n";
}

int		my_file(int error, int i)
{
	char *str;

	error_1(error, &str);
	error_2(error, &str);
	error_3(error, &str);
	error_4(error, &str);
	if (error == 94)
		str = "ERROR 94: invalid sq color \n";
	if (error == 101)
		str = "ERROR 101: invalid triangle first point \n";
	if (error == 102)
		str = "ERROR 102: invalid triangle second point side \n";
	if (error == 103)
		str = "ERROR 103: invalid triangle third point \n";
	ft_putstr_fd("Error\n", 2);
	if (i != 0)
	{
		ft_putstr_fd("(line : ", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd(")", 2);
	}
	ft_putstr_fd(str, 2);
	return (error);
}
