/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <shikma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:42:56 by shikma            #+#    #+#             */
/*   Updated: 2020/11/30 14:18:29 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_camera
{
	t_vector	lookfrom;
	t_vector	cam_d;
	double		fov;
	t_vector	horizontal;
	t_vector	low_left_c;
	t_vector	vertical;
}				t_camera;
typedef struct	s_resolution
{
	double		w;
	double		h;
}				t_resolution;
typedef struct	s_ambiant
{
	double		ka;
	t_vector	amb_p;
}				t_ambiant;
typedef struct	s_light
{
	t_vector	light_p;
	double		kl;
	t_vector	color;
	t_vector	hit;
	t_vector	normal;
	t_vector	view_direction;
	t_vector	r;
	t_vector	l;
}				t_light;
typedef struct	s_plan
{
	t_vector	plan_p;
	t_vector	plan_d;
	t_vector	plan_col;
}				t_plan;
typedef struct	s_sphere
{
	t_vector	sphere_p;
	double		diametre;
	t_vector	sphere_col;
}				t_sphere;
typedef struct	s_sq
{
	t_vector	sq_p;
	t_vector	sq_d;
	double		side_size;
	t_vector	sq_col;
}				t_sq;
typedef struct	s_cylindre
{
	t_vector	cy_p;
	t_vector	cy_d;
	double		diam;
	double		h;
	t_vector	cy_col;
	double		m1;
	double		m2;
}				t_cylindre;
typedef struct	s_triangle
{
	t_vector	tr_p1;
	t_vector	tr_p2;
	t_vector	tr_p3;
	t_vector	tr_col;
}				t_triangle;

typedef struct	s_shd
{
	t_vector	shd_p;
	t_vector	shd_d;
	t_vector	shd_obj;
	t_vector	shd_col;
	double		ks;
}				t_shd;
typedef struct	s_object
{
	t_camera		*camera;
	t_light			*light;
	t_plan			*plan;
	t_sphere		*sphere;
	t_sq			*sq;
	t_cylindre		*cy;
	t_triangle		*triangle;
	t_vector		obj_col;
	t_vector		*shd_col;
	t_shd			*shd;
	t_vector		*rot;
	t_vector		*tr;
}				t_object;

typedef struct	s_element
{
	void				*obj;
	int					id;
	struct s_element	*next;
	struct s_element	*ptr_last;
}				t_element;

typedef struct	s_cam_elm
{
	void				*cam;
	struct s_cam_elm	*next;
	struct s_cam_elm	*prev;
	struct s_cam_elm	*c_ptr_last;
}				t_cam_elm;
typedef struct	s_data
{
	t_resolution	res;
	t_ambiant		am;
}				t_data;

t_element		*add_end(t_element **liste, void *elt,
int id, size_t data_size);
t_element		*create_list(void *elt, int id, size_t data_size);
t_vector		fill_rotation(char **t);
t_vector		fill_translation(char **t);
t_ambiant		fill_ambiant(char **t);
t_camera		*fill_camera(char **t);
t_resolution	fill_resolution(char **t);
t_light			*fill_light(char **t);
void			fill_struct(char **info, t_data *data, t_object *object,
t_element **liste);
t_plan			*fill_plan(char **t);
void			list_printer(t_element *list);
void			c_list_printer(t_cam_elm *c_list);
t_sphere		*fill_sphere(char **t);
t_sq			*fill_square(char **t);
t_cylindre		*fill_cylindre(char **t);
t_triangle		*fill_triangle(char **t);
t_cam_elm		*create_c_list(void *c_elt, size_t data_size);
t_cam_elm		*add_c_end(t_cam_elm **liste, void *elt, size_t data_size);
int				nb_word(char *str);
int				my_file(int error, int i);
void			ft_putstr_fd(char *s, int fd);
int				is_int(char *t);
char			**ft_split_whitespaces(char *str);
int				check_kl_ka_fov_res(int id, char *t);
int				check_color(char *t);
int				parsing_check(int error, char **str, int argc, int *error_nb);
int				check_normal(char *t);
int				check_size(char *t);
int				check_struct(char *str, int *error_nb, char **info);
int				is_float(char *t);
int				is_2_commas(char *t);
int				check_position(char *t);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				check_extention(char *str);
int				check_general_error(char **str, int argc);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			**ft_split(char const *s, char c);
void			translate(char **info, t_object *object,
t_cam_elm **c_ptr, t_element **ptr);
void			rotate(char **info, t_object *object,
t_cam_elm **c_ptr, t_element **ptr);
t_vector		rot_x(t_vector vec, double teta);
t_vector		rot_y(t_vector vec, double teta);
t_vector		rot_z(t_vector vec, double teta);
int				res_checker(char *str, int **error_nb);
int				am_checker(char *str, int **error_nb);
int				cam_checker(char *str, int **error_nb);
int				light_checker(char *str);
int				cy_checker(char *str);
int				pl_checker(char *str);
int				sp_checker(char *str);
int				sq_checker(char *str);
int				tr_checker(char *str);
int				tra_checker(char *str);
int				rot_checker(char *str);
double			ft_atof(char *s);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				just_checking(char *str, int *er, int error);
int				my_checker_free(char *str, int error, int i);
int				my_free(void *str);
void			free_c_liste(t_cam_elm *c_liste);
void			free_liste(t_element *liste);
int				free_my_list(t_cam_elm *c_liste, t_element *liste);
void			free_tab(char **info,int n);
#endif
