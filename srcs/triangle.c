
#include"minirt.h"

double hit_triangle(t_vector cam, t_raydata *ray_info, t_object *obj)
{
	double t;
	double denominateur;

	t_vector edge0 = soustraction(obj->triangle->tr_p2 ,obj->triangle->tr_p1 )  ; 
	t_vector edge1 = soustraction(obj->triangle->tr_p3 ,obj->triangle->tr_p2 )  ; 
	t_vector edge2 = soustraction(obj->triangle->tr_p1 ,obj->triangle->tr_p3 )  ; 
	t_vector N = cross(edge0,edge1);
	N = get_normalize( N);
	denominateur = dot(ray_info->ray_direc[ray_info->id],N);
	if(fabs(denominateur)>1e-4f)
	{
		t = -dot(soustraction(cam, obj->triangle->tr_p1),N)/denominateur;
		t_vector C0 = soustraction(ray(cam,ray_info->ray_direc[ray_info->id],t) , obj->triangle->tr_p1); 
		t_vector C1 = soustraction(ray(cam,ray_info->ray_direc[ray_info->id],t) , obj->triangle->tr_p2); 
		t_vector C2 = soustraction(ray(cam,ray_info->ray_direc[ray_info->id],t) , obj->triangle->tr_p3);
		if (dot(N, cross(edge0, C0)) > 0 && dot(N, cross(edge1, C1)) > 0 && dot(N, cross(edge2, C2)) > 0)
		{
			if(t>=1e-4f)
			{
				ray_info->t = t;
				if(ray_info->max_d[ray_info->id] >t)
				{
					obj->light->hit= ray(cam,ray_info->ray_direc[ray_info->id],t);
					obj->light->normal = N;
			   
					obj->obj_col = malloc(sizeof(t_vector));
					*(obj->obj_col) = obj->triangle->tr_col;
					ray_info->max_d[ray_info->id] = t;
					return(1);
				}
			}
		}
	}
	return(0);
}