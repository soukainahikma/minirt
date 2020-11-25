/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:06:29 by shikma            #+#    #+#             */
/*   Updated: 2020/11/25 14:48:14 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void resize(int a,int b,t_move *move)
{
	if(b < move->data.res->h)
		move->data.res->h = b;
	if(a < move->data.res->w)
		move->data.res->w = a;
}

int		main(int argc, char **argv)
{
	t_move	move;
	int		error_nb[3];
	int a;
	int b;

	move.liste = NULL;
	move.c_liste = NULL;
	move.bmp = 0;
	
	if (parsing_check(0, argv, argc, error_nb) != 0)
		return (0);
	move.object.light = (t_light *)malloc(sizeof(t_light));
	move.object.light->color = (t_vector){0, 0, 0};
	move.object.light->kl = 0;
	move.object.light->light_p = (t_vector){0, 0, 0};
	parsing(&move, &move.liste, &move.c_liste, argv[1]);
	mlx_get_screen_size(move.w.mlx_ptr, &a, &b);
	resize(a,b,&move);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		move.bmp = 1;
	move.w.mlx_ptr = mlx_init();
	move.w.win_ptr = mlx_new_window(move.w.mlx_ptr, move.data.res->w, move.data.res->h, "Minirt");
	move.w.img_ptr = mlx_new_image(move.w.mlx_ptr, move.data.res->w, move.data.res->h);
	move.w.img_data = (int *)mlx_get_data_addr(move.w.img_ptr, &move.w.bpp, &move.w.size_l, &move.w.img_endian);
	move.object.camera = move.c_liste->cam;
	ft_camera(move.object.camera, (t_vector){0, 1, 0}, move.data.res->w / move.data.res->h);
	image(&move);
	if (move.bmp == 1)
		save_bmp_image(move);
	if (move.bmp == 0)
	{
		mlx_hook(move.w.win_ptr, 4, 0, press_mouse, &move);
		mlx_hook(move.w.win_ptr, 2, 0, press_key, &move);
		mlx_put_image_to_window(move.w.mlx_ptr, move.w.win_ptr, move.w.img_ptr, 0, 0);
		mlx_loop(move.w.mlx_ptr);
	}
	
	
}
