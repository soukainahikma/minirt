/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:50:26 by shikma            #+#    #+#             */
/*   Updated: 2020/11/27 13:17:36 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bmp	init_bmph(t_move move)
{
	t_bmp		res;

	res.id[0] = 'B';
	res.id[1] = 'M';
	res.file_size = 54 + 4 * (int)move.data.res->w * (int)move.data.res->h;
	res.unused = 0;
	res.offset = 54;
	res.dib = 54 - 14;
	res.width = (int)move.data.res->w;
	res.height = -(int)move.data.res->h;
	res.plane[0] = 1;
	res.plane[1] = 0;
	res.bpp[0] = 32;
	res.bpp[1] = 0;
	res.compression = 0;
	res.raw_bitmap_size = 4 * (int)move.data.res->w * (int)move.data.res->h;
	res.resx = 0;
	res.resy = 0;
	res.number_of_colors = 0;
	res.important_colors = 0;
	return (res);
}

int		save_bmp_image(t_move move)
{
	t_bmp		img;
	int			file;

	file = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	img = init_bmph(move);
	write(file, &img, 54);
	write(file, move.w.img_data, img.raw_bitmap_size);
	close(file);
	return (1);
}
