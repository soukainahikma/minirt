#include "minirt.h"

t_resolution *fill_resolution(char **t)
{
    t_resolution *res = (t_resolution *)malloc(sizeof(t_resolution));
    res->w = atof(t[1]);
    res->h = atof(t[2]);
    return(res);
}
t_vector *fill_rotation(char **t)
{
    char **t1;
    t_vector *rot = (t_vector *)malloc(sizeof(t_vector));
    t1 = ft_split(t[1],',');
    rot->x = atof(t1[0]);
    rot->y = atof(t1[1]);
    rot->z = atof(t1[2]);
    return(rot);
}
t_vector *fill_translation(char **t)
{
    char **t1;
    t_vector *tr = (t_vector *)malloc(sizeof(t_vector));
    t1 = ft_split(t[1],',');
    tr->x = atof(t1[0]);
    tr->y = atof(t1[1]);
    tr->z = atof(t1[2]);
    return(tr);
}