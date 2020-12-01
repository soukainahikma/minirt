/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:51 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 18:05:52 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

int		free_my_list(t_cam_elm *c_liste, t_element *liste)
{
	free_c_liste(c_liste);
	free_liste(liste);
	return (0);
}

void	fill_cam(char **info, t_cam_elm **c_ptr)
{
	if (info[0][0] == 'c' && info[0][1] != 'y')
	{
		if (*c_ptr == NULL)
			*c_ptr = create_c_list(fill_camera(info), sizeof(t_camera));
		else
			*c_ptr = add_c_end(c_ptr, fill_camera(info), sizeof(t_camera));
	}
}

void	parsing(t_move *move, t_element **ptr, t_cam_elm **c_ptr, char *str)
{
	char	*line;
	int		fd;
	char	**t;
	int		rest;

	fd = open(str, O_RDONLY);
	rest = 1;
	while (rest == 1)
	{
		rest = get_next_line(fd, &line);
		if (nb_word(line) == 0)
		{
			my_free(line);
			continue;
		}
		t = ft_split_whitespaces(line);
		fill_struct(t, &move->data, ptr);
		fill_cam(t, c_ptr);
		rotate(t, c_ptr, ptr);
		translate(t, c_ptr, ptr);
		my_free(line);
	}
	close(fd);
}
