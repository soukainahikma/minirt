#include "minirt.h"

t_plan *fill_plan(char **t)
{
    char **t1;
    char **t2;
    char **t3;
     t_plan *object = (t_plan *)malloc(sizeof(t_light));
    t1 = ft_split(t[1],',');
    t2 = ft_split(t[2],',');
    t3 = ft_split(t[3],',');
    object->plan_p.x = atof(t1[0]);
    object->plan_p.y = atof(t1[1]);
    object->plan_p.z = atof(t1[2]);
    
    object->plan_d.x = atof(t2[0]);
    object->plan_d.y = atof(t2[1]);
    object->plan_d.z = atof(t2[2]);
    
    object->plan_col.x = atof(t3[0]);
    object->plan_col.y = atof(t3[1]);
    object->plan_col.z = atof(t3[2]);
    return(object);
}