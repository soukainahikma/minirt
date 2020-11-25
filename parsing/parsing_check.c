/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:52:00 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 19:48:30 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			n = n * (-1);
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}

void	err_init(int **error_nb, int *i, int *rest)
{
	(*error_nb)[0] = 0;
	(*error_nb)[1] = 0;
	(*error_nb)[2] = 0;
	(*rest) = 1;
	(*i) = 0;
}

int		check_struct(char *str, int *error_nb, char **info)
{
	if (info[0][0] == 'R' && ft_strlen(info[0]) == 1)
		return (res_checker(str, &error_nb));
	else if (info[0][0] == 'A' && ft_strlen(info[0]) == 1)
		return (am_checker(str, &error_nb));
	else if (info[0][0] == 'c' && ft_strlen(info[0]) == 1)
		return (cam_checker(str, &error_nb));
	else if (info[0][0] == 'l' && ft_strlen(info[0]) == 1)
		return (light_checker(str));
	else if (info[0][0] == 'c' && info[0][1] == 'y' && ft_strlen(info[0]) == 2)
		return (cy_checker(str));
	else if (info[0][0] == 'p' && info[0][1] == 'l' && ft_strlen(info[0]) == 2)
		return (pl_checker(str));
	else if (info[0][0] == 's' && info[0][1] == 'p' && ft_strlen(info[0]) == 2)
		return (sp_checker(str));
	else if (info[0][0] == 's' && info[0][1] == 'q' && ft_strlen(info[0]) == 2)
		return (sq_checker(str));
	else if (info[0][0] == 't' && info[0][1] == 'r' && ft_strlen(info[0]) == 2)
		return (tr_checker(str));
	else if (info[0][0] == 't' && info[0][1] == 'a' && ft_strlen(info[0]) == 2)
		return (tra_checker(str));
	else if (info[0][0] == 'r' && info[0][1] == 'o' && ft_strlen(info[0]) == 2)
		return (rot_checker(str));
	return (-1);
}

int		parsing_check(int error, char **str, int argc, int *error_nb)
{
	char	*line;
	int		fd;
	int		rest_i[2];

	fd = open(str[1], O_RDONLY);
	err_init(&error_nb, &rest_i[1], &rest_i[0]);
	if (check_general_error(str, argc) != 0)
		return (my_file(check_general_error(str, argc), rest_i[1]));
	while (rest_i[0] == 1)
	{
		rest_i[0] = get_next_line(fd, &line);
		if (rest_i[0] == -1)
			return (my_file(-3, rest_i[1]));
		rest_i[1]++;
		if (nb_word(line) == 0)
			return (my_file(-2, rest_i[1]));
		error = check_struct(line, error_nb, ft_split_whitespaces(line));
		if (error != 0)
			return (my_file(error, rest_i[1]));
	}
	return (just_checking(error_nb, error));
}
