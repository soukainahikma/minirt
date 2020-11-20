#include "minirt.h"

t_light *fill_light(char **t)
{
    char **t1;
    char **t2;
    t_light *l = (t_light *)malloc(sizeof(t_light));
    t1 = ft_split(t[1],',');
    t2 = ft_split(t[3],',');
    l->light_p.x = atof(t1[0]);
    l->light_p.y = atof(t1[1]);
    l->light_p.z = atof(t1[2]);

    l->kl = atof(t[2]);

    l->color.x = atof(t2[0]);
    l->color.y = atof(t2[1]);
    l->color.z = atof(t2[2]);
    return(l);
}