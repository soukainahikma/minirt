#include "minirt.h"
t_cylindre *fill_cylindre(char **t)
{
    char **t1;
    char **t2;
    char **t3;
    t_cylindre *cy = (t_cylindre *)malloc(sizeof(t_cylindre));
    t1 = ft_split(t[1],','); 
    t2 = ft_split(t[2],',');
    t3 = ft_split(t[3],',');
    cy->cy_p.x = atof(t1[0]);
    cy->cy_p.y = atof(t1[1]);
    cy->cy_p.z = atof(t1[2]);

    cy->cy_d.x = atof(t2[0]);
    cy->cy_d.y = atof(t2[1]);
    cy->cy_d.z = atof(t2[2]);

    cy->diam = atof(t[4]);
    cy->h = atof(t[5]);

    cy->cy_col.x = atof(t3[0]);
    cy->cy_col.y = atof(t3[1]);
    cy->cy_col.z = atof(t3[2]);
    return(cy);
}