/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:48:12 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 11:47:23 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define BUFFER_SIZE 32

size_t	size_of_line(char *buff)
{
	size_t i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	return (i);
}

int		ft_reste(char **line, char **tmp, char **buff)
{
	size_t i;

	i = size_of_line(*tmp);
	*line = ft_substr(ft_strdup(*tmp), 0, i);
	*tmp = ft_substr(*tmp, i + 1, ft_strlen(*tmp));
	free(*buff);
	return (1);
}

int		ft_error(int fd, char **line, char **buff)
{
	if (line == NULL)
		return (-1);
	if ((!(*buff = (char *)malloc(BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || fd > 10240 || read(fd, *buff, 0) < 0 || BUFFER_SIZE < 0)
	{
		free(*buff);
		return (-1);
	}
	return (0);
}

int		end_of_line(char **line, char **tmp, char **buff)
{
	*line = *tmp;
	free(*buff);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*tmp[10240];
	long long	l;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	if (ft_error(fd, line, &buff) == -1)
		return (-1);
	while ((!(ft_strchr(tmp[fd], '\n'))) &&
			(l = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[l] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		if ((ft_strchr(tmp[fd], '\n')))
			return (ft_reste(line, &tmp[fd], &buff));
	}
	if (l == 0 && (!(ft_strchr(tmp[fd], '\n'))))
		return (end_of_line(line, &tmp[fd], &buff));
	free(buff);
	buff = NULL;
	if ((ft_strchr(tmp[fd], '\n')))
		return (ft_reste(line, &tmp[fd], &buff));
	free(tmp[fd]);
	return (0);
}
