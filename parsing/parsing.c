/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:51 by shikma            #+#    #+#             */
/*   Updated: 2020/11/26 14:17:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

void	fill_cam(char **info, t_data *data, t_object *object, t_cam_elm **c_ptr)
{
	t_cam_elm *p;

	if (info[0][0] == 'c' && info[0][1] != 'y')
	{
		object->camera = fill_camera(info);
		if (*c_ptr == NULL)
			*c_ptr = create_c_list(object->camera, sizeof(t_camera));
		else
			*c_ptr = add_c_end(c_ptr, object->camera, sizeof(t_camera));
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
			continue;
		t = ft_split_whitespaces(line);
		fill_struct(t, &move->data, &move->object, ptr);
		fill_cam(t, &move->data, &move->object, c_ptr);
		rotate(t, &move->object, c_ptr, ptr);
		translate(t, &move->object, c_ptr, ptr);
	}
	close(fd);
}
