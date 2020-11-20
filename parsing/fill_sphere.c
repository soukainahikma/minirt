#include "minirt.h"

t_sphere *fill_sphere(char **t)
{
    char **t1;
    char **t2;
    t_sphere *sphere = (t_sphere *)malloc(sizeof(t_sphere));
    t1 = ft_split(t[1],',');
    t2 = ft_split(t[3],',');
    sphere->sphere_p.x = atof(t1[0]);
    sphere->sphere_p.y = atof(t1[1]);
    sphere->sphere_p.z = atof(t1[2]);

    sphere->diametre = atof(t[2]);

    sphere->sphere_col.x = atof(t2[0]);
    sphere->sphere_col.y = atof(t2[1]);
    sphere->sphere_col.z = atof(t2[2]);
    return(sphere);
}