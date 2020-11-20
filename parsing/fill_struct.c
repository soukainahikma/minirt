#include "minirt.h"
void fill_struct(char **info,t_data *data,t_object *object,t_element **liste)
{
    if(info[0][0] == 'R')
    {
        data->res = fill_resolution(info);
        if(*liste == NULL)
            *liste = create_list(data->res,1,sizeof(t_resolution));
        else
            *liste = add_end(liste,data->res,1,sizeof(t_resolution));
    }
    else if(info[0][0] == 'A')
         {
        data->am = fill_ambiant(info);
          if(*liste == NULL)
            *liste = create_list(data->am,2,sizeof(t_ambiant));
        else
            *liste = add_end(liste,data->am,2,sizeof(t_ambiant));
    }
    else if(info[0][0] == 'c' && info[0][1] == 'y')
        {
        object->cy = fill_cylindre(info);
        if(*liste == NULL)
            *liste = create_list(object->cy,8,sizeof(t_cylindre));
        else
            *liste = add_end(liste,object->cy,8,sizeof(t_cylindre));
    }
    else if(info[0][0] == 'l')
    {
       object->light_n = fill_light(info);
        if(*liste == NULL)
            *liste = create_list(object->light_n,4,sizeof(t_light));
        else
            *liste = add_end(liste,object->light_n,4,sizeof(t_light));
            
    }
    else if(info[0][0] == 'p' && info[0][1] == 'l')
    {
        object->plan = fill_plan(info);
        if(*liste == NULL)
            *liste = create_list(object->plan,5,sizeof(t_plan));
        else
            *liste = add_end(liste,object->plan,5,sizeof(t_plan));
    }
    else if(info[0][0] == 's' && info[0][1] == 'p')
        {
        object->sphere = fill_sphere(info);
        if(*liste == NULL)
            *liste = create_list(object->sphere,6,sizeof(t_sphere));
        else
            *liste = add_end(liste,object->sphere,6,sizeof(t_sphere));
    }
    else if(info[0][0] == 's' && info[0][1] == 'q')
       {
        object->sq = fill_square(info);
        if(*liste == NULL)
            *liste = create_list(object->sq,7,sizeof(t_sq));
        else
            *liste = add_end(liste,object->sq,7,sizeof(t_sq));
    }
    else if(info[0][0] == 't' && info[0][1] == 'r' && info[0][2] != 'a')
        {
        object->triangle = fill_triangle(info);
        if(*liste == NULL)
            *liste = create_list(object->triangle,9,sizeof(t_triangle));
        else
            *liste = add_end(liste,object->triangle,9,sizeof(t_triangle));
    }
}