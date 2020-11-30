/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:21:51 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:07:01 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

void	fill_cam(char **info, t_object *object, t_cam_elm **c_ptr)
{
	if (info[0][0] == 'c' && info[0][1] != 'y')
	{
		//object->camera = fill_camera(info);
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
		fill_struct(t, &move->data, &move->object, ptr);
		fill_cam(t, &move->object, c_ptr);
		rotate(t, &move->object, c_ptr, ptr);
		translate(t, &move->object, c_ptr, ptr);
		my_free(line);
//		my_free(t);
	}
	close(fd);
}
