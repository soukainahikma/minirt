/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:53:31 by shikma            #+#    #+#             */
/*   Updated: 2020/12/04 12:38:40 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include "bmp.h"
# include "parsing.h"

typedef struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			img_endian;
}				t_window;
typedef struct	s_raydata
{
	t_vector	ray_direc[2];
	double		t;
	double		max_d[2];
	int			id;
}				t_raydata;

typedef struct	s_sun
{
	t_vector	diffuse;
	t_vector	ambiant;
	t_vector	specular;
}				t_sun;

typedef struct	s_move
{
	t_window	w;
	t_data		data;
	t_object	object;
	t_element	*liste;
	t_cam_elm	*c_liste;
	t_element	*ptr;
	t_vector	new_start;
	int			button;
	int			bmp;
	t_vector	sh_d;
}				t_move;

typedef struct	s_tr_help
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	h;
	t_vector	s;
	t_vector	q;
	double		a;
	double		f;
	double		u;
	double		v;
	double		t;
}				t_tr_help;

t_vector		addition(t_vector a, t_vector b);
t_vector		soustraction(t_vector a, t_vector b);
t_vector		multiplication(double a, t_vector b);
t_vector		division(double a, t_vector b);
t_vector		get_normalize(t_vector a);
t_vector		ray(t_vector origin, t_vector direction, double t);
void			ft_camera(t_camera *cam, t_vector vup, double aspect);
t_vector		cross(t_vector a, t_vector b);
double			norm(t_vector a);
double			dot(t_vector a, t_vector b);
t_vector		get_ray(t_camera *camera_, double u, double v);
int				get_color(t_vector clr);
t_vector		light(t_element *ptr, t_move *move, t_raydata *ray_);
void			calculate_light(t_object *object,
t_light *light);
t_vector		ray(t_vector origin, t_vector direction, double t);
double			hit_sphere(t_vector cam, t_raydata *ray_info,
t_object *obj);
double			hit_plan(t_vector cam, t_raydata *ray_info, t_object *obj);
double			hit_sq(t_vector cam, t_raydata *ray_info, t_object *obj);
double			hit_triangle(t_vector cam, t_raydata *ray_info, t_object *obj);
double			hit_cylinder(t_vector cam, t_raydata *ray_info, t_object *obj);
t_vector		shadow(t_element *list, t_move *all, t_vector col,
t_raydata *ray_);
double			inter(t_element *liste, t_raydata *ray_info,
t_vector data, t_object *obj);
double			check_distance(t_vector origin, t_vector light,
t_vector object, t_vector cam);
void			image(t_move *move);
int				press_key(int key, t_move *move);
int				press_mouse(int button, t_move *move);
void			sphere_translation(int key, t_move *move);
void			sq_translation(int key, t_move *move);
void			cylindre_translation(int key, t_move *move);
void			plan_translation(int key, t_move *move);
void			triangle_translation(int key, t_move *move);
void			sq_rotation(int key, t_move *move);
void			cylindre_rotation(int key, t_move *move);
void			plan_rotation(int key, t_move *move);
t_vector		draw(t_vector ray, t_move *move);
void			parsing(t_move *move, t_element **ptr, t_cam_elm **c_ptr,
char *str);
t_bmp			init_bmph(t_move move);
int				save_bmp_image(t_move	move);
double			ft_fabs(double t);

#endif
