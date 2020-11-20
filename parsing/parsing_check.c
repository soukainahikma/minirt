/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:52:00 by shikma            #+#    #+#             */
/*   Updated: 2020/11/20 11:29:37 by shikma           ###   ########.fr       */
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

int		parsing_check(int error, char **str, int argc, int *error_nb)
{
	char	*line;
	int		fd;
	int		rest;
	int		i;

	fd = open(str[1], O_RDONLY);
	err_init(&error_nb, &i, &rest);
	if (check_general_error(str, argc) != 0)
		return (my_file(check_general_error(str, argc), i));
	while (rest == 1)
	{
		rest = get_next_line(fd, &line);
		if (rest == -1)
			return (my_file(-3, i));
		i++;
		error = check_struct(line, error_nb);
		if (error != 0)
			return (my_file(error, i));
	}
	if (error_nb[0] == 0)
		return (my_file(-8, 0));
	if (error_nb[2] == 0)
		return (my_file(-9, 0));
	return (error);
}
