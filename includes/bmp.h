/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:48:07 by shikma            #+#    #+#             */
/*   Updated: 2020/11/19 08:56:25 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# pragma pack(push, 1)

typedef struct	s_bmp
{
	char		id[2];
	int			file_size;
	int			unused;
	int			offset;
	int			dib;
	int			width;
	int			height;
	char		plane[2];
	char		bpp[2];
	int			compression;
	int			raw_bitmap_size;
	int			resx;
	int			resy;
	int			number_of_colors;
	int			important_colors;
}				t_bmp;

# pragma pack(pop)

#endif
